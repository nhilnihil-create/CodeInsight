#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

ll per(int l,int r){
  ll ans=1;
  for(int i=l;i>l-r;i--){
    ans*=i;
    ans%=mod;
  }
  return ans;
}

ll ans=1;
int n,k;
vector<vector<int> > to;
void dfs(int v,int p=-1){
  int l=p==-1?k:k-2;
  int r=p==-1?to[v].size()+1:to[v].size()-1;
  ans*=per(l,r);
  ans%=mod;
  rep(i,to[v].size()){
    int nv=to[v][i];
    if(nv==p) continue;
    dfs(nv,v);
  }
}

int main(){
  cin >> n >> k;
  to.resize(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs(0);
  cout << ans << endl;
}