#include <stdio.h>
#include <stack>
typedef long long ll;

int main(void) {
  ll i, j, k, n, m;
  scanf("%lld%lld", &n, &m);
  char s[n + 10];
  scanf("%s", s);
  std::stack<ll> ans;
  for(i = n; i; ) {
    for(j = m; j; --j) if(i >= j && s[i - j] == '0') {
      i = i - j;
      ans.push(j);
      break;
    }
    if(!j) {
      printf("-1");
      return 0;
    }
  }
  while(ans.size()) printf("%lld ", ans.top()), ans.pop();
  return 0;
}