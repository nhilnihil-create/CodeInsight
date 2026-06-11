#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k;
  cin>>h>>w>>k;
  vector<vector<char>> c(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<(1<<h);i++){
    for(int j=0;j<(1<<w);j++){
      int cnt=0;
      for(int s=0;s<h;s++){
        for(int t=0;t<w;t++){
          if(1&(i>>s))continue;
          if(1&(j>>t))continue;
          if(c[s][t]=='#')cnt++;
        }
      }
      if(cnt==k)ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}