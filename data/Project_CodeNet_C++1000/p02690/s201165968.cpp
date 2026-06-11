
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void Main() {
    // input
    u_int64_t X;
    cin >> X;


    // translate
    u_int64_t LOOP_NUM = 1000000;
    for (u_int64_t D = 1; D < LOOP_NUM; D++) {
        for (long long A = -118; A <= 119; A++) {
            long long B = A - D;
            // cout << A << " " << B << endl;
            long long Apower5 = 1;
            long long Bpower5 = 1;
            for (int i = 0; i < 5; i++) {
                Apower5 *= A;
                Bpower5 *= B;
            }

            if (Apower5 - Bpower5 == X) {
                cout << A << " " << B << endl;
                return;
            }
        }
    }


    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
