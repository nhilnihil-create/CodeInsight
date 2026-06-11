#include <bits/stdc++.h>
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
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
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

int dp1[3050][3050],dp2[3050][3050];
int main(){
    int n,t;
    cin >> n >> t;
    vi a(n), b(n);
    rp(i,n) cin >> a.at(i) >> b.at(i);
    rp(i,n){
        repi(j,0,3001){
            if(i==0){
                if(j-a[i]>=0)
                dp1[0][j]=b[0];
                continue;
            }
            if(j-a[i]<0) dp1[i][j]=dp1[i-1][j];
            else dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-a[i]]+b[i]);
        }
    }
    rp(i,n){
        repi(j,0,3001){
            if(i==0){
                if(j-a[n-1-i]>=0)
                dp2[0][j]=b[n-1];
                continue;
            }
            if(j-a[n-1-i]<0) dp2[i][j]=dp2[i-1][j];
            else dp2[i][j]=max(dp2[i-1][j],dp2[i-1][j-a[n-1-i]]+b[n-1-i]);
        }
    }
    int ans=0;
    rp(i,n){
        int res=0;
        if(i==0){
            res=dp2[n-2][t-1];
        }
        else if(i==n-1){
            res=dp1[n-2][t-1];
        }
        else{
            rp(j,t){
                chmax(res,dp1[i-1][j]+dp2[n-2-i][t-1-j]);
            }
        }
        res += b[i];
        chmax(ans,res);
    }
    print(ans);
    return 0;
}