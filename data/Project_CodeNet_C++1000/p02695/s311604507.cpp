#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
int N,M,Q;
vector<int> a(50),b(50),c(50),d(50);
int ans = 0;

void dfs(vector<int> A){
    if(A.size() == N + 1){
        int calc = 0;
        rep(i,Q){
            if(A[b[i]] - A[a[i]] == c[i]) calc += d[i];
        }
        chmax(ans , calc);
        return;
    }
    A.push_back(A.back());
    while(A.back() <= M){
        dfs(A);
        A.back()++;
    }
}

int main(){
    cin >> N >> M >> Q;
    rep(i,Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(vector<int>(1,1));
    cout << ans << endl;
}