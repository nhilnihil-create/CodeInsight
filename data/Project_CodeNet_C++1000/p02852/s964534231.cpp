#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ' ';  } return os;  }

int main() {
  string s;
  int n,m; cin >> n >> m >> s;
  int len=0;
  vector<int> ans;
  loop(i,1,n+1) {
    len++;
    if (len > m) {
      cout << -1 << endl;
      return 0;
    }

    if (s[i] == '0') {
      ans.push_back(len);
      len = 0;
      continue;
    }
  }

  reverse(ans.begin(), ans.end());
  vector<int> ans2;
  ans2.push_back(ans[0]);
  loop(i,1,ans.size()) {
    if (ans2.back() + ans[i] <= m) {
      ans2.back() += ans[i];
    }
    else ans2.push_back(ans[i]);
  }
  reverse(ans2.begin(), ans2.end());
  cout << ans2 << endl;
  return 0;
}
