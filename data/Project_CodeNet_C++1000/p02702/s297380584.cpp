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

    //累積和
    vector<ll> rui(n);
    rui[0] = s[0] - '0';
    ll x = 10;
    rep(i, n - 1)
    {
        rui[i + 1] = rui[i] + (s[i + 1] - '0') * x;
        rui[i + 1] %= 2019;
        x = x * 10 % 2019;
    }

    map<ll, ll> M;
    rep(i, n)
    {
        M[rui[i]]++;
    }

    ll ans = 0;
    for (auto m : M)
    {
        ans += nCr(m.second, 2);
        if (m.first == 0)
            ans += m.second;
    }

    cout << ans << endl;
}

//なぜかだめ
//サンプルはおｋ