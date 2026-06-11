
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;



void Main() {
    // input
    u_int32_t N;
    cin >> N;
    
    vector<u_int32_t> nums(N);
    for (u_int32_t i = 0; i < N; i++) {
        cin >> nums[i];        
    }
    
    sort(nums.begin(), nums.end());
    for (u_int32_t i = 0; i < N - 1; i++) {
        if (nums[i] == nums[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
