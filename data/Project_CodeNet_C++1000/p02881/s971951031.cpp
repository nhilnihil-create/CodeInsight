#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
int main() {
  
ll n; cin>>n;  
long double a=sqrt(n);
  ll b=a/1;
  
  ll ans;
  rep(i,n){if(n%(b-i)==0){ans=b-i;break;}}
  
  ll answer=n/ans;
  
  cout<<ans+answer-2<<endl;
  
  
  
}