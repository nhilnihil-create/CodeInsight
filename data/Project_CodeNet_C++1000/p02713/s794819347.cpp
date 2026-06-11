#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      for(int k = 1; k <= n; k++){
        ans += gcd(i, gcd(j, k));
      }
    }
  }
  cout << ans << endl;

  return 0;
}
