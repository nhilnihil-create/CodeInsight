#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a; cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums.push_back(a);
    }
    auto res = 0ll;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res += nums[i] * nums[j];
        }
    }

    cout << res << endl;
}