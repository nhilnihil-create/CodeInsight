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
ll zeroh[1050];
ll zerov[1050];
void solve(){
    ll h,w,a,b;
    cin >> h >> w >> a >> b;
    ll tate=-1,yoko=-1;
    rp(i,w+1){
        rp(j,h+1){
            if((h-b-b)*i-(w-a-a)*j==a*h-b*w){
                tate=j,yoko=i;
                break;
            }
        }
    }
    if(tate<0){
        print("No");
        return;
    }
    repi(i,1,w-yoko+1) zerov[i]=b;
    repi(i,w-yoko+1,w+1) zerov[i]=h-b;
    repi(i,1,h-tate+1) zeroh[i]=a;
    repi(i,h-tate+1,h+1) zeroh[i]=w-a;
    rp(i,h){
        string str="";
        rp(j,w){
            if(zeroh[i+1]>0&&zerov[j+1]>0){
                str=str+"0";
                zeroh[i+1]--; zerov[j+1]--;
            }
            else str=str+"1";
        }
        print(str);
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}