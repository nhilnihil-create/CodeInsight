#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
using PPI=pair<P,int>;
//ll const mod=998244353;
ll const mod=1e9+7;
const ll MAX=300000;
using vi=vector<int>;
using vl=vector<ll>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////
vvi node;
int n,k;
ll dfs(int now,int par){
  ll res=1;
  int n=node[now].size()-1;//other than par
  rep(i,n)(res*=max(0LL,(k-2-i)))%=mod;
  for(auto x:node[now]){
    if(x==par)continue;
    (res*=dfs(x,now))%=mod;
  }

  return res;
}


int main(){
    
    cin>>n>>k;
    node.resize(n);
    rep(i,n-1){
      int a1,a2;
      cin>>a1>>a2;
      a1--;a2--;
      node[a1].push_back(a2);
      node[a2].push_back(a1);
    }
    ll ans=k;
    int in=node[0].size();
    rep(i,in)(ans*=(k-1-i))%=mod;
    for(auto x:node[0]){
      (ans*=dfs(x,0))%=mod;
    }
    cout<<ans<<endl;
    
    return 0;
}