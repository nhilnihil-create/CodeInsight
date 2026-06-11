#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve() {
    ll MAX = pow(10, 18);
    int n; cin >> n;
    vector<ll> nums;
    ll a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == 0) {
            return 0;
        }
        nums.push_back(a);
    }
    ll res = 1;
    for (ll num : nums) {
        if (MAX / res >= num)
            res *= num;
        else
            return -1;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
