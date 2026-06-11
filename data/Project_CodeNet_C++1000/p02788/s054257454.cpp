#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef long double ld;
typedef vector<ll>VI;
typedef pair<int,int>P;
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
#define INFTY 1LL<<60
#define MAX_INT INT_MAX
#define Endl '\n'
#define CLR(mat) memset(mat, 0, sizeof(mat))
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}//最大公約数
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}//最小公倍数
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
const int MOD = 1000000007;

inline ll mod_add(ll a,ll b){return (a+b)%MOD;}
inline ll mod_sub(ll a,ll b){return (a+MOD-b)%MOD;}
inline ll mod_mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
inline ll mod_pow(ll x,ll n,ll mod=(ll)MOD){ll res=1;while(n>0){
if(n&1)res=res*x%mod;
x=x*x%mod;n>>=1;}return res;}
inline ll mod_inv(ll x){return mod_pow(x,MOD-2);}
inline ll mod_div(ll a, ll b){return mod_mul(a,mod_inv(b));}
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17 -I .
//push_back -> emplace_back


// 区間加算にも対応した BIT
template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};
int n;
ll d,a;
VI x,h;
int main(){
   cin>>n>>d>>a;
   x.resize(n);h.resize(n);
   rep(i,n)cin>>x[i]>>h[i];
   VI ids(n);
   rep(i,n)ids[i]=i;
   sort(ALL(ids),[&](int i,int j){
      return x[i]<x[j];
   });
   VI nx(n),nh(n);
   rep(i,n)nx[i]=x[ids[i]],nh[i]=h[ids[i]];
   x=nx,h=nh;
   BIT<ll>bit(n+10);
   rep(i,n)bit.add(i+1,i+2,h[i]);
   ll res=0;
   rep(i,n){
      ll cur=bit.sum(i+1,i+2);
      if(cur<=0)continue;
      ll need=(cur+a-1)/a;
      ll right=x[i]+d*2;
      int id=upper_bound(ALL(x),right)-x.begin();
      bit.add(i+1,id+1,-need*a);
      res+=need;
   }
   cout<<res<<endl;
}