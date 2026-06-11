#include <stdio.h>
typedef long long ll;

ll n;
char s[20];

void dfs(ll a, char c) {
  if(a == n) {
    printf("%s\n", s);
    return;
  }
  ll i;
  for(i = 'a'; i <= c; ++i) {
    s[a] = i;
    dfs(a + 1, c);
  }
  s[a] = c + 1;
  dfs(a + 1, c + 1);
}

int main(void) {
  scanf("%lld", &n);
  s[0] = 'a', s[n] = 0;
  dfs(1, 'a');
  return 0;
}