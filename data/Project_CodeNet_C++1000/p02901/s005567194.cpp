#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for (int i = (int)(n)-1; i>=0; --i)
#define call(var) cerr<<#var<<"="<<var<<"\n";
#define dup(x,y) (((x)+(y)-1)/(y))
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const double pi = acos(-1);
template<class t,class u> inline bool chmax(t&a,u b){if(a<b){a=b;return true;}return false;}
template<class t,class u> inline bool chmin(t&a,u b){if(b<a){a=b;return true;}return false;}

// newer
#define For(i,a,b) for(auto i=(a);i<=(b);++i)
#define rFor(i,a,b) for(auto i=(b);i>=(a);--i)

// 実験中
void cerrall(const vector<bool>& a){rep(i,a.size()) cerr << i << " " << (a[i]? "True" : "False") << "\n"; cerr << "\n";}
template<class T> void cerrall(const vector<T>& a){for(auto& t : a) cerr << t << " "; cerr << "\n";}
template<class T> void cerrall(const set<T>& a){for(auto& t : a) cerr << t << " "; cerr << "\n";}
template<class T> void cerrall(const multiset<T>& a){for(auto& t : a) cerr << t << " "; cerr << "\n";}
template<class T, class U> void cerrall(const vector<pair<T,U>>& a){rep(i,a.size()) cerr << i << " : " << a[i].first << " " << a[i].second << "\n";}
template<class T, class U> void cerrall(const map<T,U>& a){for(auto& t : a) cerr << t.first << " " << t.second << "\n";}
template<class T, class U> void cerrall(const unordered_map<T,U>& a){for(auto& t : a) cerr << t.first << " " << t.second << "\n";}


int main(){
    int n,m;cin >> n >> m;
    vi a(m);
    vi keys(m);
    rep(i,m){
        int b;
        cin >> a[i] >> b;
        rep(j,b){
            int ai;cin >> ai;
            --ai;
            keys[i] |= (1<<ai);
        }
    }

    //rep(i,m) cout << "i = " << i << " = " << bitset<12>(keys[i]) << "\n";

    vector<vi> dp(m+1,vi((1<<n)+10,INF));
    dp[0][0] = 0;
    for(int i=0;i<m;++i){
        for(int j=0;j<(1<<n);++j){
            chmin(dp[i+1][j | keys[i]], dp[i][j] + a[i]);
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    int ans = dp[m][(1<<n)-1];
    cout << (ans == INF? -1 : ans) << "\n";
}