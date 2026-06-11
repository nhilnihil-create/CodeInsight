#include <bits/stdc++.h>
using namespace std;

struct data {
  long long n, x, m;
};

long long k, q;
vector<long long> d, t;
vector<data> v;

void solve();
long long calc(long long n, long long x, long long m);

int main() {
  cin >> k >> q;
  d.resize(k);
  v.resize(q);
  for(int i = 0; i < k; ++i) cin >> d[i];
  for(int i = 0; i < q; ++i)
    cin >> v[i].n >> v[i].x >> v[i].m;
  solve();
  return 0;
}

void solve() {
  t = d;
  for(int i = 0; i < q; ++i) {
    d = t;
    v[i].x %= v[i].m;
    for(int j = 0; j < k; ++j) d[j] %= v[i].m;
    cout << calc(v[i].n, v[i].x, v[i].m) << endl;
  }
}

long long calc(long long n, long long x, long long m) {
  long long res = 0, sum = x;
  for(int i = 0; i < k; ++i) {
    sum += (n - 1) / k * d[i] + ((n - 1) % k > i) * d[i];
    if(d[i] == 0) res += (n - 1) / k + ((n - 1) % k > i);
  }
  res += sum / m;
  return n - 1 - res;
}