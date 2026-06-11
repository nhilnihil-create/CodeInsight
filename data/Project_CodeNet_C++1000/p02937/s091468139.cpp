#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, n, q, a, b, ans = -1, now;
  char s[100010], t[100010];
  vector<ll> vec[26];
  scanf("%s%s", s, t);
  for(i = 0; s[i]; ++i) vec[s[i] - 'a'].push_back(i);
  n = i;
  for(i = 0; t[i]; ++i) {
    t[i] -= 'a';
    if(!vec[t[i]].size()) {
      printf("-1");
      return 0;
    }
    now = upper_bound(vec[t[i]].begin(), vec[t[i]].end(), ans % n) - vec[t[i]].begin();
    if(now != vec[t[i]].size()) ans = ans / n * n + vec[t[i]][now];
    else ans = (ans / n + 1) * n + vec[t[i]][0];
  }
  printf("%lld", ans + 1);
  return 0;
}