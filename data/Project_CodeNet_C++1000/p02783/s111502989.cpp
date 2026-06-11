
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int32_t H, A;
    cin >> H >> A;


    // process
    u_int32_t count = 0;
    count = H / A;
    if (H % A != 0) {
        count++;
    }

    // output
    cout << count << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
