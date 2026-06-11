#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int p,q,r;
  cin>>p>>q>>r;
  int ans=min(p+q,q+r);
  ans=min(ans,r+p);
  cout<<ans;
}
      