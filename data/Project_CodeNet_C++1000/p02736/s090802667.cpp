#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, now = 0;
  scanf("%lld", &n);
  char a[n + 10];
  bool b = true;
  scanf("%s", a);
  queue<ll> q, t;
  for(i = 0; i < n; ++i) {
    q.push(a[i] - '1');
    if(a[i] == '2') b = false;
  }
  while(q.size() != 1) {
    if(q.size() & 1) {
      t.push(q.front()), q.pop();
      while(q.size()) q.pop(), t.push(q.front()), q.pop();
    } else {
      now = q.front(), q.pop();
      while(q.size()) t.push(q.front() > now ? q.front() - now : now - q.front()), now = q.front(), q.pop();
    }
    while(t.size()) q.push(t.front()), t.pop();
  }
  printf("%lld", b ? q.front() : (q.front() & 1 ? 1 : 0));
  return 0;
}