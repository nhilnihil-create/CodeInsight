#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;


int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
        ll ans = 0;
        for (int mul = 1; mul <= n; mul++) {
                int k = n / mul;
                ans += (ll) k * mul * (1 + k) / 2;
        }
 
        cout << ans;
  return 0;
}