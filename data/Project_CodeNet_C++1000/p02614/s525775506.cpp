#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

char grid[10][10];

int main(){
  int h,w,k;
  cin>>h>>w>>k;
  rep(i,h)rep(j,w){
    cin>>grid[i][j];
  }
  int ans=0;
  rep(i,1<<h){
    rep(j,1<<w){
      int now=0;
      rep(hi,h)rep(wi,w){
        if(i>>hi&1 || j>>wi&1)continue;
        if(grid[hi][wi]=='#') now++;
      }
      if(now==k)ans++;
    }
  }
  cout<<ans<<endl;
}
