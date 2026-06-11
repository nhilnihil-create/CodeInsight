#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define PI 3.141592653589793
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const ll INF = 1LL << 56;

//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main(){
    ll n;
    cin >> n;
    ll a[n];
    for (ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=0,x=1;
    for (ll i=0;i<61;i++){
        ll even=0,odd=0;
        for (ll j=0;j<n;j++){
            if (a[j]&(1LL<<i))odd++;
            else even++;
        }
        ll p=(((odd%MOD)*(even%MOD))%MOD)*x;
        ans+=p;
        ans%=MOD;
        x*=2;
        x%=MOD;
    }
    cout << ans << endl;
    return 0;
}
