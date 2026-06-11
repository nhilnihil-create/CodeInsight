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

void solve(){
    ll n,m,s,t;
    cin >> n >> m;
    matrix G(n*3);
    rp(i,m){
        ll u,v;
        cin >> u >> v;
        u--; v--;
        G[u*3].pb(v*3+1);
        G[u*3+1].pb(v*3+2);
        G[u*3+2].pb(v*3);
    }
    cin >> s >> t;
    s--; t--;
    queue<PLL> que;
    que.push(mp(s*3,0));
    vi seen(n*3,0);
    while(!que.empty()){
        PLL p=que.front(); que.pop();
        if(seen[p.first]==1) continue;
        if(p.first==t*3){
            print(p.second/3);
            return;
        }
        seen[p.first]=1;
        for(auto nod:G[p.first]){
            que.push(mp(nod,p.second+1));
        }
    }
    print(-1);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}