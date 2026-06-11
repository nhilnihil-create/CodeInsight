#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  REP(i, n) {
    cin >> vec[i];
  }
  int ans = 0;
  for(int i = 1; i < n-1; i++) {
    vector<int> tmp={vec[i-1], vec[i], vec[i+1]};
    sort(tmp.begin(), tmp.end());
    // cout << "[ ";
    // REP(i, tmp.size()) {
    //   cout << tmp[i] << " ";
    // }
    // cout << " ]" << endl;
    if (tmp[1] == vec[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}