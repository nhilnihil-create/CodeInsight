#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, m, n) for(ll i = m; i > n; i--)
#define Rep(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define lmax(x, y) max<ll>(x, y)
#define lmin(x, y) min<ll>(x, y)
#define tmax(x, y, z) lmax((x), lmax((y), (z)))
#define tmin(x, y, z) lmin((x), lmin((y), (z)))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
const ll INF = 1LL << 60;
const ll MM = 1000000000; const ll MOD = MM + 7; const ll MMM=9223372036854775807;//2^63 -1
#define ADD(a,b) a = (a + ll(b)) % MOD
#define MUL(a,b) a = (a * ll(b)) % MOD
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){ fill( (T*)array, (T*)(array+N), val );}
// struct edge{ ll from, to, cost; };
// struct edge{ ll to, cost; };
// using Graph = vector<vector<ll>>;  // 重み無し
// using Graph = vector<edge>;  // 辺
// using Graph = vector<vector<edge>>;  // 重み付き
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//cout << fixed << setprecision(10);
// priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    string s; cin >> s;
    ll k, f = 1, b = 1, sig = 0, sz = s.size(); cin >> k;
    // 最初の連続数を数える
    rep(i, sz-1){
        if(s[i] == s[i+1]) f++;
        else break;
    }
    // 最後の連続数を数える
    rrep(i, sz-1, -1){
        if(s[i] == s[i-1]) b++;
        else break;
    }
    // s単独の必要置換数を数える
    ll tmp = 1;
    rep(i, sz){
        if(s[i] != s[i+1] || i == sz-1) sig += tmp/2, tmp = 1;
        else tmp++;
    }
    // 最初と最後が別の文字
    if(s[0] != s[sz-1]){
        cout << sig * k << endl;
        return 0;
    }
    // 最後まで連続
    if(f == sz){
        cout << f*k/2 << endl;  // f/2*kではない
        return 0;
    }
    cout << (sig-f/2-b/2)*k + f/2 + b/2 + (f+b)/2*(k-1) << endl;
}
