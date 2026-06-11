#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n;cin >> n;
  
  double ans=0.000000;
  rep(i, n) {
    ll a; cin>>a;
    ans+=1.0/a;
  }
  
  ans=1.0/ans;
  
  cout << fixed << setprecision(7);
  cout << ans << endl;
}