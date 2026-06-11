#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

int solve() {
    int N, L; cin >> N >> L;
    vector<int> nums(N);
    iota(nums.begin(), nums.end(), L);
    int total = accumulate(nums.begin(), nums.end(), 0);
    
    int min_diff = numeric_limits<int>::max();
    int min_val{0};
    for (auto num : nums) {
        if (abs(num) < min_diff) {
            min_diff = abs(num);
            min_val = num;
        }
    }
    
    return total - min_val;
}

int main() {
    cout << solve() << endl;
}

