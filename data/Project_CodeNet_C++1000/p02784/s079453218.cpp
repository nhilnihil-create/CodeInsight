
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int32_t H, N;
    cin >> H >> N;
    u_int32_t sum = 0;
    for (u_int32_t i = 0; i < N; i++) {
        u_int32_t A;
        cin >> A;
        sum += A;
    }


    // process


    // output
    if (sum >= H) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
