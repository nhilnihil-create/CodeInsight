#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int h,w,k;
  cin>>h>>w>>k;
  vector<vector<char>> gori(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
    cin>>gori[i][j];
    }
  }
  int ans=0;
  rep(i,1<<h){
    rep(j,1<<w){
      int ima=0;
      rep(hi,h)rep(wi,w){
        if(i>>hi&1 || j>>wi&1){
          continue;
        }
           if(gori[hi][wi]=='#'){
            ima++;
           }
      }
      if(ima==k){
        ans++;
      }
    }
  }
cout<<ans<<endl;
  }