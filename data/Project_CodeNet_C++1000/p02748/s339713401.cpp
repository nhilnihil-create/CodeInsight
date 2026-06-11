#include <bits/stdc++.h>
using namespace std;
int i,j,a,b,m,n;
int main(){
  cin>>a>>b>>m;
  vector<int> A(a),B(b);
  vector<int> x(m),y(m),c(m);
  int am=100000,bm=100000;
  for(i=0;i<a;i++)cin>>A[i],am=min(am,A[i]);
  for(i=0;i<b;i++)cin>>B[i],bm=min(bm,B[i]);
  for(i=0;i<m;i++)cin>>x[i]>>y[i]>>c[i];
  int ans=am+bm;
  for(i=0;i<m;i++)ans=min(ans,(A[x[i]-1]+B[y[i]-1]-c[i]));
  cout<<ans;
}