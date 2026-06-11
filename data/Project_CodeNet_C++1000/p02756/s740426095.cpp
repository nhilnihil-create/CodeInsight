#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string S;
  cin >> S;

  int Q;
  cin >> Q;

  deque<char> ans;
  for (char c : S) ans.push_back(c);

  bool reversed = false;
  rep(i,0,Q-1) {
    int t;
    cin >> t;

    if (t == 1) reversed = !reversed;
    else {
      int f; char C;
      cin >> f >> C;

      if (reversed) {
        if (f == 1) ans.push_back(C);
        else ans.push_front(C);
      } else {
        if (f == 1) ans.push_front(C);
        else ans.push_back(C);
      }
    }
  }

  auto print = [](const char& n) { cout << n; };

  if (reversed) {
    for_each(ans.rbegin(), ans.rend(), print);
  } else {
    for_each(ans.begin(), ans.end(), print);
  }

  cout << endl;

  return 0;
}
