#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int total = accumulate(nums.begin(), nums.end(), 0);
    int left{0},right{total};
    
    int res = right - left;
    for (int i = 0; i <n; ++i) {
        left += nums[i];
        right -= nums[i];
        res = min(res, abs(right - left));
    }

    return res;
}

int main() {
    cout << solve() << endl;
}