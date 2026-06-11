#include<bits/stdc++.h>
using namespace std;
int main(void){
  int i,n,m;cin>>n>>m;
  vector<int> h(n);
  for(i=0; i<n; ++i) cin>>h[i];
  vector<int> a(m),b(m);
  for(i=0; i<m; ++i) cin>>a[i]>>b[i];
  
  vector<int> t(n,0);
  for(i=0; i<m; ++i){
    t[a[i]-1]|=h[a[i]-1]-h[b[i]-1]-1;
    t[b[i]-1]|=h[b[i]-1]-h[a[i]-1]-1;
  }
  int cnt=0;
  for(i=0; i<n; ++i) if(t[i]>=0) ++cnt;
  cout<<cnt<<endl;
  return 0;
}
