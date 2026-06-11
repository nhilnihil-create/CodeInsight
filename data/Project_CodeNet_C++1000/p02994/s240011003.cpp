#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,l;
  cin>>n>>l;

  int ans = n*l + n*(n-1)/2;
  if(l>0) ans -=l;
  else if(l<=-n) ans -= (l+n-1);

  cout<<ans<<endl;


  return 0;
}