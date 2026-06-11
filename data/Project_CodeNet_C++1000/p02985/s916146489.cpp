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

vvi v;
int K;

ll perm(ll n,int k) {
  if(!k) return 1;
  return n*perm(n-1,k-1)%INF;
}

void dfs(int now,int par,ll &ans) {
  int num=v[now].size();
  if(par!=-1) ans*=perm(K-2,num-1);
  else ans*=perm(K,num+1);
  ans%=INF;
  for(int x:v[now]) {
    if(x==par) continue;
    dfs(x,now,ans);
  }
}

int main() {
  int N;
  cin >> N >> K;
  v=vvi(N);
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  
  ll ans=1;
  dfs(0,-1,ans);
  
  cout << ans << endl;
}