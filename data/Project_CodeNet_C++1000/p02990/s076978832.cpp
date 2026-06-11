#include<iostream>

using namespace std;

const int MAX = 2 * 100000;
const int MOD = 1000000007;

typedef long long ll;

ll factorial[MAX], factorialInvers[MAX], invers[MAX];

void ComInit(){
    factorial[0] = factorial[1] = 1;
    factorialInvers[0] = factorialInvers[1] = 1;
    invers[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        factorial[i] = factorial[i - 1] * i % MOD;
        invers[i] = MOD - (MOD / i) * invers[MOD % i] % MOD;
        factorialInvers[i] = factorialInvers[i - 1] * invers[i] % MOD;
    }
}

ll Combination(ll n,ll k)
{
    if(n<k)
        return 0;
    if(n<0||k<0)
        return 0;
    return (factorial[n] * factorialInvers[k] % MOD) * factorialInvers[n - k] % MOD;
}

int main (){
    ComInit();
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        ll ans = Combination(n - k + 1, i) * Combination(k - 1, i - 1) % MOD;
        cout << ans << endl;
    }

    return 0;
}