#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const ll DIV =1e9+7;
//const double PI = M_PI;
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
#define chmax(a,b) a=max(a,b)

/*Coding Space*/
int ans[500][500] = {};
void u(int a,int b,int now){
  ans[a][b] = now;
  ans[b][a] = now;
}
void dfs(int t,int cnt, int now){
  if(cnt == 2){
    u(t,t+1,now);
  }else if(cnt == 3){
    u(t,t+1,now);
    u(t,t+2,now);
    u(t+1,t+2,now+1);

  }else{
    bool dd = cnt%2;
    int nt = t + cnt/2;
    rep(i,cnt/2)rep(j,cnt/2+dd){
      u(i+t,nt+j,now);
    }
    dfs(t,cnt/2,now+1);
    dfs(nt,cnt/2+dd,now+1);
  }
}
int main(){
  int n; cin >> n;
  dfs(0,n,1);
  rep(i,n){
    rep(j,n){
      if(i == j) continue;
      if(i > j)  continue;
      cout << ans[i][j];
      if(j != n-1) cout << ' ';
    }
    cout << endl;
  }
}
