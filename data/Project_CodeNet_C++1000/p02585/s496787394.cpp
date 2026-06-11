#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll i=0; i<n; i++)
#define frep(i,m,n) for(ll i=m; i<=n; i++)

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll n, k, ans = -1*INF; cin >> n >> k;
    vector<ll> p(n), c(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) cin >> c[i];

    rep(i, n) {
        ll m = -1*INF, now = p[i]; // 得点、現在地
        vector<ll> sum(1, 0);
        sum.push_back(c[now]);
        while(now != i) {
            ll len = sum.size();
            now = p[now];
            sum.push_back(sum[len-1]+c[now]);
        }

        ll len = sum.size()-1; // サイクルの長さ
        if(k < len) {
            frep(j, 1, k) {
                if(m < sum[j]) m = sum[j];
            }
        }
        else if(sum[len] < 0) {
            frep(j, 1, len) {
                if(m < sum[j]) m = sum[j];
            }
        }
        else {
            frep(j, 0, k%len) {
                if(m < sum[j]) m = sum[j];
            }
            ll a = sum[len]*(k/len) + m;
            frep(j, 0, len) {
                if(m < sum[j]) m = sum[j];
            }
            ll b = sum[len]*(k/len-1) + m;
            if(a < b) m = b;
            else m = a;
        }
        if(ans < m) ans = m;
    }

    cout << ans << endl;

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
