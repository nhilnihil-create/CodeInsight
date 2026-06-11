#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

bool Check(ll n, ll m, ll v, ll p, vector<ll> a, int ind) {
  ll sum = (p - 1) * m;
  ll cap = a[ind] + m;
  for (int i = p - 1; i < n; ++i) {
    ll can = cap - a[i];
    if (can < 0) {
      return false;
    }
    if (can > m) {
      can = m;
    }
    sum += can;
  }
  return sum >= m * v;
}

int main()
{
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x;
  }
  sort(a.rbegin(), a.rend());
  int left = 0, right = n;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (Check(n, m, v, p, a, middle)) {
      left = middle;
    } else {
      right = middle;
    }
  }
  cout << left + 1 << endl;
  return 0;
}
