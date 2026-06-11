#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

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
    ll h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<ll>> d(h, vector<ll>(w, INF));
    if(s[0][0] == '.') d[0][0] = 0;
    else d[0][0] = 1;

    queue<P> q;
    q.push(MP(0, 0));
    while(!q.empty()) {
        ll x = q.front().first, y = q.front().second;
        q.pop();
        if(x+1 < h) {
            if(s[x][y] == '.' && s[x+1][y] == '#') {
                if(d[x+1][y] > d[x][y] + 1) {
                    d[x+1][y] = d[x][y] + 1;
                    q.push(MP(x+1, y));
                }
            }
            else {
                if(d[x+1][y] > d[x][y]) {
                    d[x+1][y] = d[x][y];
                    q.push(MP(x+1, y));
                }
            }
        }
        if(y+1 < w) {
            if(s[x][y] == '.' && s[x][y+1] == '#') {
                if(d[x][y+1] > d[x][y] + 1) {
                    d[x][y+1] = d[x][y] + 1;
                    q.push(MP(x, y+1));
                }
            }
            else {
                if(d[x][y+1] > d[x][y]) {
                    d[x][y+1] = d[x][y];
                    q.push(MP(x, y+1));
                }
            }
        }
    }

    cout << d[h-1][w-1] << endl;

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
