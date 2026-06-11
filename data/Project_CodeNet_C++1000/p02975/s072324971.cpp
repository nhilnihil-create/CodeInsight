#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, a;
map<int, int> cnt;

int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    ++cnt[a];
  }
  if (cnt.size() == 1) {
    puts(cnt[0] == n ? "Yes" : "No");
  } else if (cnt.size() == 2) {
    int a = cnt.begin()->second, b = cnt.rbegin()->second;
    if (a > b) swap(a, b);
    puts((2 * a == b && cnt[0] == a) ? "Yes" : "No");
  } else if (cnt.size() == 3) {
    int sum = 0, flag = 1;
    for (auto it : cnt) {
      sum ^= it.first;
      flag &= it.second == n / 3;
    }
    puts((!sum && flag) ? "Yes" : "No");
  } else {
    puts("No");
  }
}
