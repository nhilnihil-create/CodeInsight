#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e6 + 10;

int n;

void No() {
  puts("No");
  exit(0);
}
vector<pii> E;
void print() {
  puts("Yes");
  for (int i = 0; i < E.size(); ++i) {
    printf("%d %d\n", E[i].x, E[i].y);
  }
  exit(0);
}
long computeXOR(const int n) {
  switch (n & 3)
  {
  case 0: return n;
  case 1: return 1;
  case 2: return n + 1;
  case 3: return 0;
  }
}
int main() {
  cin >> n;
  E.clear();
  for (int i = 0 ; i <= 20; ++i) {
    if (n == (1 << i)) {
      No();
    }
  }
  int mx = ((n / 4) - 1) * 4 + 3;
  if (n % 4 == 3)mx = n;
  if (n % 4 == 0)mx = n - 1;
  for (int i = 1 ; i + 1 <= mx; ++i)E.push_back(make_pair(i, i + 1));
  E.push_back(make_pair(mx, n + 1));
  for (int i = 1 + n; i + 1 <= n + mx; ++i)E.push_back(make_pair(i, i + 1));
  if (n % 4 == 1) {
    E.push_back(make_pair(mx + 1, mx + 2));
    E.push_back(make_pair(mx + 2, 1));
    E.push_back(make_pair(1, mx + 1 + n));
    E.push_back(make_pair(mx + 1 + n, mx + 2 + n));
  }
  if (n % 4 == 2) {
    E.push_back(make_pair(mx + 1, mx + 3));
    E.push_back(make_pair(mx + 1, mx + 2));
    E.push_back(make_pair(mx + 1, 2));
    E.push_back(make_pair(2, mx + 3 + n));
    E.push_back(make_pair(mx + 3 + n, mx + 1 + n));
    E.push_back(make_pair(3, mx + 2 + n));
  }
  if (n % 4 == 0) {
    E.push_back(make_pair(mx - 1, mx + 1 + n));
    bool f = false;
    for (int i = 1 ; i < n; ++i) {
      if (i + 1 == 2 * n || i + 1 == n)continue;
      if (computeXOR(i) == (computeXOR(mx - 1) ^ (mx + 1))) {
        E.push_back(make_pair(i + 1, mx + 1));
        f = true;
        break;
      }
    }
  }
  print();

  return 0;
}