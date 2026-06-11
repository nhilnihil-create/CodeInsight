#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////
string s;
matrix dp;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>s;
    dp.resize(2,Vi(s.size()+1,INF));
    dp[0][0]=s[s.size()-1]-'0';
    if(dp[0][0]!=0)dp[1][0]=10-dp[0][0];
    rep(i,s.size()-1){
        chmin(dp[0][i+1],dp[0][i]+s[s.size()-i-2]-'0');
        if(s[s.size()-i-2]!='9'){
            chmin(dp[1][i+1],dp[0][i]+10-s[s.size()-i-2]+'0');
            chmin(dp[0][i+1],dp[1][i]+s[s.size()-i-2]-'0'+1);
            chmin(dp[1][i+1],dp[1][i]+10-s[s.size()-i-2]+'0'-1);
        }else{
            chmin(dp[1][i+1],dp[1][i]);
            chmin(dp[1][i+1],dp[0][i]+1);
        }
    }
    ll ans = dp[0][s.size()-1];
    chmin(ans,dp[1][s.size()-1]+1);
    print(ans);
    return 0;
}