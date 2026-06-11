#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef long double ld;
typedef vector<ll>VI;
typedef pair<ll,ll>P;
#define VV(T) vector<vector<T>>
#define sz(x) int(x.size())
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i,n) for (ll i=(ll)n-1;i>=0;i--)
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX6 1001001//6
#define MAX7 10010010//7
#define SENTINEL 2000000000//9
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
#define CLR(mat) memset(mat, 0, sizeof(mat))
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}//最大公約数
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}//最小公倍数
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
const int MOD = 1000000007;
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17
//push_back -> emplace_back

ll nCr(ll n,ll k,ll MOD_=1000000007){
    //assert(n>=0&&k>=0&&MOD_>=2);
    ll size=k;
    ll ans=1;
    vector<ll>fact_inv,inv;
    fact_inv.resize(size+5);
    inv.resize(size+5);
    fact_inv[0]=fact_inv[1]=1;
    inv[1]=1;
    for(int i=2;i<size+5;i++){
        inv[i]=MOD_-inv[MOD_%i]*(MOD_/i)%MOD_;
        fact_inv[i]=fact_inv[i-1]*inv[i]%MOD_;
    }
    for(int i=n;i>=n-k+1;i--){
        ans*=i;ans%=MOD_;
    }
    return ans*fact_inv[k]%MOD_;
}

int main(){
   ll X,Y;
   cin>>X>>Y;
   if((X+Y)%3 || X*2<Y || Y*2<X){
      cout<<0<<endl;
      return 0;
   }
   ll min_xy=min(X,Y);
   ll t=(X+Y)/3;
   ll R=min_xy-t;
   cout<<nCr(t,R)<<endl;
}