#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  ll ans=0;
  if(n%2==0) {
    ll m=10;
    while(n/m>0) {
      ans+=n/m;
      m*=5;
    }
  }
  cout << ans << endl;
  return 0;
}