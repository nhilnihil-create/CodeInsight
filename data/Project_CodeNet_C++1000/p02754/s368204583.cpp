#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
int main() {

  ll n,a,b;
  cin>>n>>a>>b;
  
  ll s=a+b;
  ll ans=0;
  ll z=0;
  if(n<s){ans=min(a,n);}
  else {ans=(n/s)*a+min(n%s,a);}
  
  cout<<ans<<endl;

  
}
