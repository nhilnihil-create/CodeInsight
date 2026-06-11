#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n, k; cin >> n >> k;
    vector<int> nums;
    int a;
    for (int i = 0 ; i < n; ++i) {
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = 0; i < k; ++i) {
        res += nums[i];
    }

    return res;
}

int main() {
	cout << solve() << endl;
}
