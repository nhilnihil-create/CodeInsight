#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e9;
const int Bmax=2e5;

int main(){
  int n; cin>>n;
  int a,x,y;
  vector<vector<int>> g(n,vector<int>(n)); // g[i][j]: iの人の証言でjの人に関して．
  rep(i,n) rep(j,n) g[i][j]=-1;

  rep(i,n){//入力
    cin>>a;
    rep(j,a){
      cin>>x>>y;
      x--;
      g[i][x]=y;
    }
  }
  // 10の表記
  int ans=0;
  rep(i,1<<n){
    vector<int>d(n);
    int num=0;
    rep(j,n) if(i>>j&1){
      d[j]=1;
      num++;
    }else{
      d[j]=0;
    }
    bool ok=true;


    rep(j,n){
      if(d[j]==1){
        rep(k,n){
          if(g[j][k]==1 && d[k]==0){
            ok=false;
            break;
          }
          if(g[j][k]==0 && d[k]==1){
            ok=false;
            break;
         }
        }
      }

      if(!ok) break;
    }
    if(ok) ans=max(ans,num);



  }
  cout<<ans<<endl;




}
