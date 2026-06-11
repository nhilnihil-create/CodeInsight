#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  vector<vector<int>> ans(h,vector<int>(w));
  rep(i,b)rep(j,a) ans[i][j]++;
  for(int i=b;i<h;i++)for(int j=a;j<w;j++) ans[i][j]++;
  rep(i,h){
    rep(j,w) cout<<ans[i][j];
    cout<<endl;
  }
}