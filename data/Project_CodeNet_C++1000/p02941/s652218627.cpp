#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pi;

#define fi first
#define se second

int read() {
  int res = 0, w = 1; char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') c = getchar(), w = -1;
  while (isdigit(c)) res = (res << 1) + (res << 3) + c - '0', c = getchar();
  return res * w;
}

const int N = 2e5 + 10;

int a[N], b[N], n, vis[N]; 
priority_queue <pi> Heap;

int main() {
  int n = read();
  ll ans = 0;
  for (int i = 1; i <= n; i++) b[i] = read();
  for (int i = 1; i <= n; i++) a[i] = read(), Heap.push(make_pair(a[i], i));
  while (!Heap.empty()) {
    pi tmp = Heap.top(); Heap.pop();
    if (b[tmp.second] == tmp.first) continue;
    if (b[tmp.second] > tmp.first) { puts("-1"); return 0; }
    int dis = tmp.first - b[tmp.second];
    int sum = a[tmp.second - 1] + a[tmp.second + 1];
    if (tmp.second == 1) sum += a[n];
    if (tmp.second == n) sum += a[1];
    if (sum > dis) { puts("-1"); return 0; }
    int add = dis / sum; ans += add;
    a[tmp.second] -= add * sum;
    tmp.first = a[tmp.second];
    Heap.push(tmp);
  }
  cout << ans << endl;
  return 0;
}