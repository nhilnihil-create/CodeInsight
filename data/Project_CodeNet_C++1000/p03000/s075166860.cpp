#include <bits/stdc++.h>
using namespace std;
int main() {
  int b=0,n,x,l,d=0; cin>>n>>x;
  while(d<=x&&b<=n) cin>>l,d+=l,b++;
  cout<<b;
}