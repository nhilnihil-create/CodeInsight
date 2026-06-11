
#include <iostream>
#include <iomanip>
using namespace std;

u_int64_t attack(u_int64_t H) {
    if (H == 1) {
        return 1;
    } else {
        return 1 + 2 * attack(H / 2);
    }
}

void Main() {
    // input
    u_int64_t H;
    cin >> H;



    // output
    cout << attack(H) << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
