#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;

ll nCr(ll n, ll r)
{
    ll num = 1;
    for (ll i = 1; i <= r; i++)
    {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main()
{
    string s;
    cin >> s;
    ll n = s.length();
    reverse(s.begin(), s.end());
    int x = 1;
    int tot = 0;
    vector<int> cnt(2019);
    ll ans = 0;
    rep(i, n)
    {
        cnt[tot]++;
        tot += (s[i] - '0') * x;
        tot %= 2019;
        ans += cnt[tot];
        x = x * 10 % 2019;
    }

    cout << ans << endl;
}

//sunuke