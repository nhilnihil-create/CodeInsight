#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
const int MOD = 1000000007;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

const int MAX = 1010101;
long long moto[MAX], gyaku[MAX], inv[MAX];
//inverse elsement 逆元
void ncr_shokika() {
    moto[0] = moto[1] = 1;
    gyaku[0] = gyaku[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        moto[i] = moto[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        gyaku[i] = gyaku[i - 1] * inv[i] % MOD;
    }
}
long long ncr(int n, int r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return moto[n] * (gyaku[r] * gyaku[n - r] % MOD) % MOD;
}
int main()
{
    int x, y;
    cin >> x >> y;
    if((x+y)%3!=0){
        cout<<0;
        return 0;
    }
    int a=(x+y)/3;
    int b=(2*y-x)/3;
    ncr_shokika();
    cout<<ncr(a,b)<<endl;
    return 0;
}
