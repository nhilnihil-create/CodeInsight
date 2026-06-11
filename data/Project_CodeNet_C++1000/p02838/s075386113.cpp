#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, 60)
    { //桁ごとにやる
        ll p = 0, q, tmp;
        rep(j, n)
        {
            if (a[j] & (1LL << i)) //(a[j]&(1<<i))←LLつけたらAC　or　a[j] >> i & 1
                p++;
        }
        q = n - p;
        tmp = p * q % MOD;
        rep(j, i) tmp = tmp * 2 % MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
}

//bit全探索時なんかに元がll型なら1LLとしないとオーバーフローの可能性？