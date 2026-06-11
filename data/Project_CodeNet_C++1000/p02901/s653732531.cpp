#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,m,a,b,c,d,e,i,j;
  cin>>n>>m;
  vector<vector<int>> dp(m+1,vector<int>(1<<n));
  for(j=1;j<(1<<n);j++) dp.at(0).at(j)=1e9;
  for(i=1;i<=m;i++){
    cin>>a>>b;
    d=0;
    for(j=0;j<b;j++){
      cin>>c;
      d+=(1<<(c-1));
    }
    for(j=0;j<(1<<n);j++) dp.at(i).at(j)=dp.at(i-1).at(j);
    for(j=0;j<(1<<n);j++){
      e=min(dp.at(i-1).at(j|d),dp.at(i-1).at(j)+a);
      if(e<dp.at(i).at(j|d)) dp.at(i).at(j|d)=e;
    }
  }
  if(dp.at(m).at((1<<n)-1)==1e9) cout<<-1<<endl;
  else cout<<dp.at(m).at((1<<n)-1)<<endl;
}