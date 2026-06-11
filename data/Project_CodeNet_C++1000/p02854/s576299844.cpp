#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  ll n;cin>>n;
  vector<ll> a(n);
  ll sum = 0;
  fr(i, n) cin>>a[i], sum+=a[i];
  ll r = 0;
  ll x = 1000000000000;
  fr(i, n) {
    r+=a[i];
    x = min(x, abs(2*r-sum));
  }
  cout << x << endl;

  return 0;
}