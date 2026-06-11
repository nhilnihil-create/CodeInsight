#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());  // 昇順に並べる
    return ret;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> nums = divisor(n);

    ll x, y;
    if (nums.size() % 2 == 0) {  // even
        x = nums.at(nums.size() / 2 - 1);
        y = nums.at(nums.size() / 2);
    } else {
        x = nums.at(nums.size() / 2);
        y = nums.at(nums.size() / 2);
    }

    ll ans = (x - 1) + (y - 1);

    cout << ans << endl;

    return 0;
}
