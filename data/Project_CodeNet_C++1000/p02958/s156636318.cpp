#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) {
    cin >> vec[i];
  }
  bool ok = true;
  for(int j = 0; j < n-1; j++) {
    if (vec[j] >= vec[j+1]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
    return 0;
  }
  rep(i, n) {
    for(int j = i+1; j < n; j++) {
      swap(vec[i], vec[j]);
      bool ok = true;
      for(int k = 0; k < n-1; k++) {
        if (vec[k] >= vec[k+1]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << "YES" << endl;
        return 0;
      }
      swap(vec[i], vec[j]);
    }
  }
  cout << "NO" << endl;
  return 0;
}