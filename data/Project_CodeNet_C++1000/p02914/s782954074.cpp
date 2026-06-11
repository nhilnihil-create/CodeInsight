#include <bits/stdc++.h>
using namespace std;
long sub(vector<long> v) {
  const int n = v.size();
  int ci = 0;
  for (int k = 60; k >= 0; --k) {
    int pi = -1;
    for (int i = ci; i < n; ++i) {
      if (v[i] & (1l << k)) {
        pi = i;
        break;
      }
    }
    if (pi == -1) continue;
    
    swap(v[ci], v[pi]);
    for (int i = 0; i < n; ++i) {
      if (i == ci) continue;
      if (v[i] & (1l << k)) {
        v[i] ^= v[ci];
      }
    }
    ++ci;
  }
  
  long ret = 0;
  {
    int ci = 0;
    for (int k = 60; k >= 0; --k) {
      if (!(v[ci] & (1l << k))) continue;
      if (!(ret & (1l << k))) {
        ret ^= v[ci];
      }
      ++ci;
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<long> a;
  for (int i = 0; i < n; ++i) {
    long tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  
  long sum = accumulate(a.begin(), a.end(), 0l, bit_xor<long>());
  vector<long> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(a[i] & (~sum));
  }
  
  cout << (sum + 2 * sub(v)) << endl;
}
