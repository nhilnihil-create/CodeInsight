#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

const int MAX = 2001;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    ll N, K;
    cin >> N >> K;

    COMinit();

    for (int i = 1; i <= K; ++i)
    {
        ll ans;
        if (i == 1)
        {
            ans = N - K + 1;
        }
        else
        {
            if (i - 1 <= N - K)
            {
                ll sum = 0;
                for (int j = i - 1; j <= N - K; ++j)
                {
                    sum = (sum + (COM(j - 1, i - 2) * (N - K - j + 1)) % MOD) % MOD;
                }
                ans = (COM(K - 1, i - 1) * sum) % MOD;
            }
            else
            {
                ans = 0;
            }
            
        }
        cout << ans << endl;
    }
}
