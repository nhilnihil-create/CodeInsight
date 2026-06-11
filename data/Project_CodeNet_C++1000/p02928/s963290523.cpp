#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll in = 0, out = 0;
    rep(i, n){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]) {
                in++;
            }
        }
        rep(k, n) if (a[i] > a[k]) {
            out++;
        }
    }
    cout << ((in * k)%MOD + ((out * ((k * (k - 1))%MOD))%MOD * modinv(2, MOD))%MOD) % MOD << endl;
    return 0;
}