#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (ll i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using ld=long double;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
const long double PI = acos(-1.0);
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int par[100010];//親
int rnk[100010];// rankだと怒られる

void init(int n){//初期化
  for(int i=0;i<n;i++){
     par[i]=i;
     rnk[i]=1;
  }
}

int find(int x){//親を求める
  if(par[x]==x) return x;
  return par[x]=find(par[x]);
}

void unite(int x,int y){//union
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(rnk[x]<rnk[y]){//rankが小さい方にくっつける
    par[x]=y;
  }
  else{
   par[y]=x;
    if(rnk[x]==rnk[y])rnk[x]++;//rankが同じ時は1増やす
  }
}

bool same(int x,int y){
 return find(x)==find(y); 
}

int main(){//cout<<fixed<<setprecision(20);
  int n,m;
  cin>>n>>m;
  init(n);
  rep(i,0,m){
   int a,b;
    cin>>a>>b;
    a--;b--;
    unite(a,b);
  }
  int ans=0;
  rep(i,0,n){
   if(!same(0,i)){
     ans++;
     unite(0,i);
   }
  }
  cout<<ans<<endl;
}