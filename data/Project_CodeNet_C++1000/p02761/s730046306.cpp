#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> vec(3, -1);
  rep(i, m) {
    int d, v;
    cin >> d >> v;
    if (vec[d-1] != -1 && vec[d-1] != v) {
      cout << -1 << endl;
      return 0;
    }
    vec[d-1] = v;
  }
  if (n != 1 && vec[0] == 0) {
    cout << -1 << endl;
    return 0;    
  }
  if (n == 1) {
    int v = vec[0] != -1 ? vec[0] : 0;   
    cout << v << endl;
    return 0;    
  }
  int ans = 0;
  int k = n-1;
  rep(i, n) {
    int v = (vec[i] != -1) ? vec[i] : (i == 0 ? 1 : 0);
    ans += v * pow(10, k);
    k--;
  }
  cout << ans << endl;

  return 0;
}