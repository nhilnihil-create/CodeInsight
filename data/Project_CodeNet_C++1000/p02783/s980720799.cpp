#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll h,a;
  cin >> h >> a;
  ll ans;
  if(h%a==0)ans=h/a;
  else ans=h/a+1;
  cout << ans << endl;
}
