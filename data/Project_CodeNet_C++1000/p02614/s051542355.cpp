#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main(){
  int h,w,k;	cin >> h >> w >> k;
  vector<vector<char>>	c(h);
  rep(i,h)rep(j,w){
    char ch;	cin >> ch;
    c[i].push_back(ch);
  }
  
  auto	check=[&](int i,int j){
    int cnt=0;
    for(int x=0;x<h;x++){
      for(int y=0;y<w;y++){
        if(!((i>>x)&1&&(j>>y)&1))	continue;
        if(c[x][y]=='#')	cnt++;
      }
    }
    return cnt;
  };
  
  int ans=0;
  for(int i=0;i<(1<<h);i++){
    for(int j=0;j<(1<<w);j++){
      int cnt=check(i,j);
      if(cnt==k){
        ans++;
      }
    }
  }
  cout << ans;
}