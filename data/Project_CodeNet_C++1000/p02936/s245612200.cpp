#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vi d,check,ans;
vvi v;

void dfs(int now,int par,int sum) {
  sum+=check[now];
  ans[now]=sum;
  for(int x:v[now]) {
    if(x==par) continue;
    dfs(x,now,sum);
  }
}

int main() {
  int N,Q;
  cin >> N >> Q;
  vi a(N-1),b(N-1);
  v=vvi(N);
  rep(i,N-1) {
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  vi p(Q),x(Q);
  rep(i,Q) {
    cin >> p[i] >> x[i];
    p[i]--;
  }
  
  d=vi(N,1),check=vi(N),ans=vi(N);
  rep(i,Q) check[p[i]]+=x[i];
  dfs(0,-1,0);
  rep(i,N) cout << ans[i] << ' ';
  cout << endl;
}