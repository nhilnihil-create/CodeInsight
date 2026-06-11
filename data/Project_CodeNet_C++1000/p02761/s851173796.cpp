#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n, m;

bool is_ok(vector<pair<int, int>> &conditions, vector<int> &target) {
  if (target.size() != n) return false;

  rep(i, m) {
    if (target[conditions[i].first - 1] != conditions[i].second) return false;
  }
  return true;
}

int main()
{  
  cin >> n >> m;
  vector<pair<int, int>> vec;
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    vec.push_back(make_pair(s, c));
  }
  if (n == 1 && m == 0) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, m) {
    if (n > 1 && vec[i].first == 1 && vec[i].second == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  int ans =  1000;
  repr(i, 999) {
    int r = i/10;
    vector<int> seq(1, i%10);
    while(r) {
      seq.push_back(r%10);
      r /= 10;
    }

    reverse(seq.begin(), seq.end());
    if (is_ok(vec, seq)) ans = min(ans, i);
  }
  cout << (ans == 1000 ? -1 : ans) << endl;
  return 0;
}