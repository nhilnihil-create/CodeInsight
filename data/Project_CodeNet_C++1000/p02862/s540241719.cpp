#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


const int MAX = 5100000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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
    long long X, Y; cin >> X >> Y;

    COMinit();

    long long X1, Y1, X2, Y2;
    X1 = Y1 = X2 = Y2 = 0;
    
    while(true)
    {
        ++X1; ++Y1;
        if(Y1 > Y || X1 > X)
        {
            cout << 0 << endl;
            return 0;
        }
        if(Y - Y1 + X - X1 == X1)
        {
            break;
        }
    }

    X2 = X - X1; X1 -= X2;
    Y2 = Y - Y1; Y1 -= Y2;
    long long ans = 0;

    //cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;

    ans = COM(X1 + X2, X1);

    cout << ans << endl;
}