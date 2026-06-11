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
    string s;
    cin >> s;
    ll n=s.size(),x=2019;
    ll a[n+1];
    fill(a,a+n+1,0);
    ll tmp=0;
    ll mod=1;
    for (ll i=0;i<n;i++){
        tmp+=(ll(s[n-1-i]-'0'))*mod;
        a[i+1]+=tmp%x;
        mod*=10;
        mod%=x;
    }
    ll ans=0,c[2019];
    fill(c,c+2019,0);
    for (ll i=0;i<n+1;i++){
        c[a[i]]++;
    }
    for (ll i=0;i<2019;i++){
        ans+=((c[i]*(c[i]-1))/2);
    }
    cout << ans << endl;
    return 0;
}
