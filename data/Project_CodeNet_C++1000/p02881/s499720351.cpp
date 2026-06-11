#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  ll ans = 1e13;

  for (int i = 1; i <= sqrt(n); i++){
    if(n % i == 0){
      ll y = n / i;
      ans = min(ans, (y - 1 + i - 1));

    }
  }
  cout << ans;
}
