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

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    Vi a(n);
    rp(i,n) cin >> a.at(i);
    Sort(a);
    ll lim = a.at(p-1);
    ll lowest;
    ll sum=0;
    repi(i,p,n){
        if(a.at(i)<lim-m){
            lowest=i;
            break;
        }
        sum += lim-a.at(i);
        if(i==n-1)lowest=n;
    }
    ll between=lowest-p;
    if(v<=n-between){
        print(lowest);
        return 0;
    }
    for(ll i=lowest-1; i>=p; i--){
        sum-=lim-a.at(i);
        if(m*(v-(n-(i-p+1)))<=sum+(a.at(i)+m-lim)*(i-p+1)){
            print(i+1);
            return 0;
        }
    }
    print(p);
    return 0;
}