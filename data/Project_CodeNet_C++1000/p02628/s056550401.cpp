#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for (int &a : nums) {
        cin >> a;
    }

    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = 0; i < k; ++i) {
        res += nums[i];
    }    
	cout << res << endl;
}
