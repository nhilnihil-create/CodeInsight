#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,d;
  cin>>n>>d;
  int x[n][d];
  int cnt=0;
  rep(i,n)rep(j,d)cin>>x[i][j];
  
  int ians=0;
  double fans=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      for(int k=0;k<d;k++){
        ians+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
        fans+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      ians=sqrt(ians);
      fans=sqrt(fans);
      if(ians==fans)cnt++;
      ians=0;
      fans=0;
    }
  }
  cout<<cnt<<endl;
  return 0;
}