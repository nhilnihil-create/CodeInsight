#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
const ll MOD = 1000000007;
ll lpowmod(ll a, ll N)
{
    ll res = 1;
    for (ll i = 0; i < N; i++)
    {
        res = res * a % MOD;
    }
    return res;
}

int main()
{
    ll N;
    cin >> N;
    ll res = lpowmod(10, N) - lpowmod(9, N) - lpowmod(9, N) + lpowmod(8, N);
    res%=MOD;
    res=(res+MOD)%MOD;
    cout << res << endl;
}