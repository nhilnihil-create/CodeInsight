#include<bits/stdc++.h>
using namespace std;
int main(void){
  int k,n; cin>>k>>n;
  vector<int> a(n),d(n);
  for(int i=0; i<n; ++i) cin>>a[i];
  int m=0;
  for(int i=0; i<n; ++i){
    if(i<n-1) d[i]=a[i+1]-a[i]; else d[i]=k-(a[i]-a[0]);
    m=max(m,d[i]);
  }
  cout<<k-m;
  return 0;
}
  