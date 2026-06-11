#include <bits/stdc++.h>  // ver2.3.4
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,k) upper_bound(ALL(a),k)-lower_bound(ALL(a),k)
#define BIGGER(a,k) a.end()-upper_bound(ALL(a),k)
#define SMALLER(a,k) lower_bound(ALL(a),k)-a.begin()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define VTiii vector<Tiii>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define _ <<' '<<
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){if(!a[lY].empty()){Vout(a[lY]);}else cout<<endl;}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
#define VVerr(a) rep(J,0,a.size()){if(!a[J].empty()){Verr(a[J]);}else cerr<<'.'<<endl;}
#define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define PI 3.141592653589793238462
#define MOD 1000000007  //  10^9 + 7
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;} // 最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;} // 最小公倍数lcm
int mypow(int x, int n, int m){ // 累乗x^n(mod m) O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int scomb(int n, int r){if((n-r)<r)r=n-r; // nCr(小さい場合)
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
int comb(int n, int r){if((n-r)<r)r=n-r; // nCr(%MOD)
int a=1;for(int i=n;i>n-r;--i){a=a*i%MOD;}for(int i=1;
i<r+1;++i){a=a*mypow(i,MOD-2,MOD)%MOD;}return a%MOD;}
Vi stpowV(){Vi a(100001);
a[0]=1;repeq(i,1,100000)a[i]=a[i-1]*i%MOD;return a;}
//Vi stpow = stpowV();  // 階乗配列(%MOD)
void press(auto &v){v.erase(unique(ALL(v)),v.end());} // 圧縮
Vi Vsum(Vi &v){Vi S(v.size()+1);rep(i,1,S.size())S[i]+=v[i-1]+S[i-1];return S;} // 累積和
int keta(int k,int i){string s = itos(k);return s[s.size()-i]-'0';} // i桁目の数字


int v, e; // 頂点数、辺数
const int MAX_N = 100010; // 頂点数の最大値
vector<int> g[MAX_N]; // 隣接リスト
bool used[MAX_N];
vector<int> ans; // トポロジカルソートされた数列

void dfs(int u) {
  if(used[u]) return;
  used[u] = true;
  for(auto& i: g[u]) dfs(i);
  // 帰りがけ順で追加
  ans.push_back(u);
}

void tsort() {
  for(int i=0; i<v; ++i) dfs(i);
  reverse(ans.begin(), ans.end());
}



signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  
  cin >> v >> e;
  
  rep(i,0,e) {
    int s, t;
    cin >> s >> t;
    //s--,t--;  // 1-indexの場合
    g[s].push_back(t);
  }
  
  tsort();
  
  //Vout(ans);
  rep(i,0,ans.size()){
    cout << ans[i] << endl;
  }
  return 0;
}
