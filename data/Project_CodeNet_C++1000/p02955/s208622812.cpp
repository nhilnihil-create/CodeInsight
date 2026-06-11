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
    ll n,k;
    cin >> n >> k;
    ll sum=0;
    Vi a(n);
    rp(i,n) {
        cin >> a.at(i);
        sum += a.at(i);
    }
    Vi div;
    for(ll i=1; i*i<=sum; i++){
        if(sum%i==0) div.pb(i);
    }
    for(auto d:div){
        ll st=sum/d;
        ll divsum=0;
        ll ki=k;
        Vi mods(n);
        rp(i,n) {
            divsum += a.at(i)/st;
            mods.at(i)=a.at(i)%st;
        }
        sort(all(mods));
        rp(i,n-(d-divsum)){
            ki -= mods.at(i);
        }
        if(ki>=0){
            print(st);
            return;
        }
    }
    reverse(all(div));
    for(auto d:div){
        ll divsum=0;
        ll ki=k;
        Vi mods(n);
        rp(i,n){
            divsum += a.at(i)/d;
            mods.at(i)=a.at(i)%d;
        }
        sort(all(mods));
        rp(i,n-(sum/d-divsum)){
            ki -= mods.at(i);
        }
        if(ki>=0){
            print(d);
            return;
        }
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}