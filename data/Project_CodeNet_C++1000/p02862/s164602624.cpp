#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


#define MAX 5100000
#define MOD 1000000007

//fac: 階乗、finv: 階乗の逆元(invの積)、inv: ある数の逆元(フェルマーの小定理より)
ll fac[MAX], finv[MAX], inv[MAX];

//テーブルを作る前処理
void combModInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll comb(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll X, Y;
    cin >> X >> Y;

    combModInit();

    if(Y > 2 * X || 2 * Y < X || (X + Y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll moves = (X + Y) / 3;
    ll up = X - moves;
    ll ans = comb(moves, up);

    cout << ans << endl;

    return 0;
}


