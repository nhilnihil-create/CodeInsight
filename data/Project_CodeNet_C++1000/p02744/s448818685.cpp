#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
int main() {
  int N;
  cin >> N;
  vector<string> vs;
  vs.push_back("a");
  rep(i, N - 1) {
    vector<string> vs2;
    for (auto s : vs) {
      char last = 'a';
      for (auto c : s) {
        last = max(c, last);
      }
      for (char si = 'a'; si < last + 2; si++) {
        vs2.push_back(s + si);
      }
    }
    swap(vs, vs2);
  }
  for (auto s : vs) {
    cout << s << endl;
  }
  return 0;
}
