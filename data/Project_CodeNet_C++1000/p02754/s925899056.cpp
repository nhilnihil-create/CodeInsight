#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll c = a+b;
  ll ans = a * (n/c);
  ans += min(n%c, a);
  cout << ans << endl;
}
