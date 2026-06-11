#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define FI(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (b); i >= (a); --i)
#define DEBUG(x) cerr << #x << ": " << (x) << '\n';


int main() {
  int n;
  cin >> n;
  multiset<int> se;
  for (int i = 0; i < (1 << n); ++i) {
    int x;
    scanf("%d", &x);
    se.insert(x);
  }
  vector<int> s;
  s.push_back(*prev(se.end(), 1));
  se.erase(prev(se.end(), 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0, tn = s.size(); j < tn; ++j) {
      int x = s[j];
      auto it = se.lower_bound(x);
      if (it == se.begin()) return puts("No"), 0;
      --it;
      s.push_back(*it);
      se.erase(it);
    } 
    sort(s.begin(), s.end(), greater<int>());
  }
  puts("Yes");
}
