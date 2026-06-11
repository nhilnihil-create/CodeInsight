
#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
#define i64         unsigned long long 
#define rep(i, n)   for(i64 i = 0; (i) < ((i64)(n)); ++(i))
#define bit(n)      (((i64)1)<<((i64)(n)))
#define sz(v)       ((i64)((v).size()))



void kill()
{
  cout << -1 << endl;
  exit(0);
}

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  priority_queue<pair<i64, i64>> q;
  rep(i, n) q.push(make_pair(b[i], i));

  i64 ans = 0;
  while(0 < sz(q)){
    // DEBUG(q);
    i64 i = q.top().second;
    q.pop();
    if(b[i] == a[i]) continue;
    if(b[i] < a[i]) kill();

    i64 prev = (i - 1 + n) % n;
    i64 next = (i + 1 + n) % n;
    i64 total = b[prev] + b[next];
    i64 times = (b[i]- a[i]) / total;
    // DEBUG(b[i], total, times);
    if(times == 0) kill();
    ans += times;
    b[i] -= total * times;
    q.push(make_pair(b[i], i));
  }

  cout << ans << endl;
}
