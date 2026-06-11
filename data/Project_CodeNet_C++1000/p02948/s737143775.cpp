#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
int n, m;
multiset<int> available;
vector<int> job[N];
 
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    job[a].push_back(b);
  }
 
  int ans = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int x : job[m - i])
      available.insert(x);
    if (!available.empty()) {
      ans += *prev(available.end());
      available.erase(prev(available.end()));
    }
  }
  printf("%d\n", ans);
  return 0;
}