#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
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
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> ans(h,vector<int> (w,0));
    rep(i,h) cin >> s[i];
    rep(i,h){
        int cnt = 0;
        int start = 0;
        rep(j,w){
            if(s[i][j] == '.'){
                cnt++;
            }else{
                rep(k,j - start) ans[i][k + start] = cnt;
                start = j+1;
                cnt = 0;
            }
        }
        if(cnt != 0){
            rep(k,w - start) ans[i][k + start] = cnt;
        }
    }
    int res = 0;
    rep(i,w){
        int cnt = 0;
        int start = 0;
        rep(j,h){
            if(s[j][i] == '.'){
                cnt++;
            }else{
                rep(k,j - start) chmax(res,ans[k + start][i] + cnt - 1);
                start = j+1;
                cnt = 0;
            }
        }
        if(cnt != 0){
            rep(k,h - start) chmax(res,ans[k+start][i] + cnt - 1);
        }
    }
    cout << res << "\n";
}