#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll modPow(const ll a, const ll n, const ll p)
{
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    ll num = modPow(a, n / 2, p);
    return (num * num) % p;
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll allComb = modPow(2, n, MOD);
    allComb = allComb != 0 ? allComb - 1 : MOD - 1;

    ll resA = 1;
    REP(i, a)
    {
        resA *= n - i;
        resA = resA % MOD;
    }
    ll resInvA = 1;
    REP(i, a)
    {
        resInvA *= i + 1;
        resInvA = resInvA % MOD;
    }
    resInvA = modPow(resInvA, MOD - 2, MOD);
    resA = (resA * resInvA) % MOD;

    ll resB = 1;
    REP(i, b)
    {
        resB *= n - i;
        resB = resB % MOD;
    }
    ll resInvB = 1;
    REP(i, b)
    {
        resInvB *= i + 1;
        resInvB = resInvB % MOD;
    }
    resInvB = modPow(resInvB, MOD - 2, MOD);
    resB = (resB * resInvB) % MOD;

    ll ans = allComb;
    ans = ans - resA < 0 ? ans - resA + MOD : ans - resA;
    ans = ans - resB < 0 ? ans - resB + MOD : ans - resB;

    cout << ans << endl;
}
