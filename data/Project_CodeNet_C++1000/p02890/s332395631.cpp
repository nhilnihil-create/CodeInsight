#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (3e5) + 5;
int n, a[N];
int freq[N];
int ac[N];

int f(int x, int& pos) {
  while (pos >= 0) {
    if (freq[pos] < x) break;
    pos--;
  }
  return (pos >= 0? ac[pos] : 0) + x * (n - pos - 1);
}

int main() { // claudio van
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    freq[a[i] - 1]++;
  }
  sort(freq, freq + n);
  partial_sum(freq, freq + n, ac);
  int ans = n, pos = n - 1;
  for (int k = 1; k <= n; ++k) {
    while (ans > 0) {
      if (k <= f(ans, pos) / ans) break;
      ans--;
    }
    printf("%d\n", ans);
  }
  return 0;
}