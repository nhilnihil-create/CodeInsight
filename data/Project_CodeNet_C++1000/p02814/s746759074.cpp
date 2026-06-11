#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

const int MAX = 510000;

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

ll calcGCD(ll a, ll b) {
    if(b == 0)return a;
    return calcGCD(b, a % b);
}

ll calcLCS(ll a, ll b) {
    if(b > a)swap(a, b);
    return a * b / calcGCD(a, b);
}

int getMultipleOf2Num(ll x) {
    int ret = 0;
    while(x % 2 == 0) {
        ++ret;
        x /= 2;
    }
    return ret;
}

int main() {
    ll N, M; cin >> N >> M;
    int cnt2;
    ll a[N];
    ll LCS = 1;
    rep(i, N) {
        cin >> a[i];
        a[i] /= 2;
        if(i == 0)cnt2 = getMultipleOf2Num(a[i]);
        LCS = calcLCS(a[i], LCS);
        if(cnt2 != getMultipleOf2Num(a[i]) || LCS > M) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << M / LCS / 2 + ((M / LCS % 2 == 0) ? 0 : 1) << endl;
}
