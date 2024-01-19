#include "secure_serial.h"
secure_serial bt;

// const uint8_t shared_secret[] = {
//     116,246,174,229,44,159,237,86,47,14,85,149,142,79,114,211,165,217,188,145,219,201,54,164,31,238,147,204,51,117,251,46
// };

void setup() {
    Serial.begin(115200);
    LOG_START
    bt.begin(2, 3, true);  // 2 -> TXD 3 -> RXD    
    // bt.set_shared_secret(shared_secret);
    bt.initial_sequence();
    LOG_END
}

void loop() {
    bt.send_msg("This is an encrypted message!", 29);
    delay(1000);
    bt.send_from_serial();
}
