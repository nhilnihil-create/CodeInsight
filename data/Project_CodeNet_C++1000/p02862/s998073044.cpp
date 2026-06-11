#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

const int MAX = 1000001;

vector<long long> fac(MAX), finv(MAX), inv(MAX);

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
    if (n < k || n < 0 || k < 0) {
        return 0;
    }
    
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    int X, Y;
    cin >> X >> Y;

    int j;
    long long answer = 0;

    COMinit();

    for(int i = 0; i < 500001; i++) {
        j = X - 2*i;
        if(3*i == 2*X - Y && 3*j == 2*Y - X) {
            answer = COM(i+j, i);
            break;
        }
    }
    
    cout << answer << endl;
	return 0;
}