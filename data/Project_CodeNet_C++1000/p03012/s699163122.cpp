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
  int a[n];
  int sumr = 0, suml = 0, ans = 10005;
  rep(i, n) {
    cin >> a[i];
    sumr += a[i];
  }
  if(n == 2){
    cout << abs(a[0] - a[1]) << endl;
    return 0;
  }
  rep(i, n - 1){
    suml += a[i];
    sumr -= a[i];
    ans = min(ans, abs(suml - sumr));
  }
  cout << ans << endl;
  return 0;
}