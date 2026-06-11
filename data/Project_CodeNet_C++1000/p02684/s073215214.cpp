#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; long long k; cin>>n>>k;
  vector<int> a(n+1);
  for(int i=1; i<=n; ++i) cin>>a[i];
  vector<int> b,d; vector<bool> c(n+1,false);
  for(int i=a[1]; c[i]==false; i=a[i]){ b.push_back(i); c[i]=true;}
  c=vector<bool>(n+1,false);
  for(int i=a[b.back()]; c[i]==false; i=a[i]){ d.push_back(i); c[i]=true;}
  if(--k>=b.size()) cout<<d[(k-b.size())%(d.size())]; else cout<<b[k%b.size()];
  return 0;
}
