#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll len = s.length();
    ll tmp = 0, ans = 0, x = 1;
    map<ll, ll> mp;
    mp[0] = 1;

    rep(i, 0, len)
    {
        tmp = (tmp + x * (s[len - 1 - i] - '0')) % 2019;
        ans += mp[tmp % 2019];
        mp[tmp % 2019]++;
        x = x * 10 % 2019;
    }
    cout << ans << endl;
}
