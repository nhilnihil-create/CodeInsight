#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll solve() {
    int n, k; cin >> n >> k;
    vi nums;
    int a;
    for (int i = 0 ; i < n; ++i) {
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());

    ll res = 0;
    for (int i = 0; i < k; ++i) {
        res += nums[i];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
