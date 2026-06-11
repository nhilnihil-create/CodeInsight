#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long llint;

const int MAXN = 1e5 + 10;

int x, y, a, b, c;
int p[MAXN], q[MAXN], r[MAXN];

int main(void) {
  scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
  for (int i = 0; i < a; ++i) scanf("%d", &p[i]);
  for (int i = 0; i < b; ++i) scanf("%d", &q[i]);
  for (int i = 0; i < c; ++i) scanf("%d", &r[i]);

  sort(p, p + a); reverse(p, p + a);
  sort(q, q + b); reverse(q, q + b);
  sort(r, r + c); reverse(r, r + c);

  vector<int> v;
  for (int i = 0; i < x; ++i) v.push_back(p[i]);
  for (int i = 0; i < y; ++i) v.push_back(q[i]);
  for (int i = 0; i < c; ++i) v.push_back(r[i]);

  sort(v.begin(), v.end()); reverse(v.begin(), v.end());

  llint sol = 0;
  for (int i = 0; i < x + y; ++i) sol += (llint) v[i];

  printf("%lld\n", sol);
  return 0;
}
