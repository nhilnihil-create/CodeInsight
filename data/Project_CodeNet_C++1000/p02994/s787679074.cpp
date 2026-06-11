#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,l,s=0,d=210; cin>>n>>l;
  s=(l+l+n-1)*n/2;
  for(int i=l;i<l+n;i++) d=min(d,abs(i));
  cout<<(s<0?s+d:s-d);
}