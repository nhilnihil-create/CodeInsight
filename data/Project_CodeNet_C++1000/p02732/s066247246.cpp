
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int64_t N;
    cin >> N;
    u_int64_t nums[N+1];
    u_int64_t A[N+1];
    for (u_int64_t i = 0; i <= N; i++) {
        nums[i] = 0;
    }
    
    for (u_int64_t i = 1; i <= N; i++) {
        u_int64_t num_A;
        cin >> num_A;
        nums[num_A]++;
        A[i] = num_A;
    }


    // translate
    u_int64_t comb = 0;
    for (u_int64_t i = 1; i <= N; i++) {
        // cout << "i: " << nums[i] << endl;
        comb += nums[i] * (nums[i] - 1) / 2;
    }


    // output
    for (u_int64_t i = 1; i <= N; i++) {
        cout << comb - nums[A[i]] + 1 << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
