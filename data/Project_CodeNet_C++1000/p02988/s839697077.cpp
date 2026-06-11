#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int res{0};
    for (int i = 1; i < n - 1; ++i) {
        if ((nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) 
            || (nums[i - 1] > nums[i] && nums[i] > nums[i + 1])) {
            res++;
        }
    }
    
    return res;
}

int main() {
    cout << solve() << endl;
}