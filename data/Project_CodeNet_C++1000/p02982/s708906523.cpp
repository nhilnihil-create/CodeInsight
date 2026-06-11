#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i=(int)s;i<(int)n;i++)
int main() {
  int n,d,x[15][15],c=0; cin>>n>>d;
  rep(i,0,n) rep(j,0,d) cin>>x[i][j];
  rep(j,0,d) x[n][j]=x[0][j];
  rep(i,0,n){
    rep(j,i+1,n){
      double dis=0;
      rep(k,0,d) dis+=pow(abs(x[i][k]-x[j][k]),2);
      dis=sqrt(dis);
      if(dis==(int)dis) c++;
    }
  }
  cout<<c;
}