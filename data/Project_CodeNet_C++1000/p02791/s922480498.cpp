
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int32_t N;
    cin >> N;
    u_int32_t nums[N];

    for (u_int32_t i = 0; i < N; i++) {
        cin >> nums[i];
    }

    u_int32_t count = 0;
    u_int32_t min = 200000 + 1;
    // process
    for (u_int32_t i = 0; i < N; i++) {
        if (nums[i] < min) {
            count++;
            min = nums[i];
        }
    }

    // output
    cout << count << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
