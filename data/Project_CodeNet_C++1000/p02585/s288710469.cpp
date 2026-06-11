#include <bits/stdc++.h>
using namespace std;

vector<vector<long>> find_cycle(vector<long> to) {
  long n = to.size();
  vector<vector<long>> ret;
  vector<long> vec(n, -1);
  for (long v = 0; v < n; v++) {
    if (vec.at(v) == -1) {
      long nv = v;
      do {
        vec.at(nv) = v;
        nv = to.at(nv);
      } while (vec.at(nv) == -1);
      if (vec.at(nv) == v) {
        vector<long> tmp;
        long end = nv;
        do {
          tmp.push_back(nv);
          nv = to.at(nv);
        } while (nv != end);
        ret.push_back(tmp);
      }
    }
  }
  return ret;
}

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i), P.at(i)--;
  vector<long> C(N);
  for (int i = 0; i < N; i++) cin >> C.at(i);

  auto FC = find_cycle(P);
  long ans = LONG_MIN;
  
  for (auto fc : FC) {
    long n = fc.size();
    long sum = 0;
    for (auto a : fc) sum += C.at(a);
    if (sum <= 0) {
      for (auto a : fc) {
        long now = a;
        long tmp = 0;
        long cnt = min(K, n);
        while (cnt--) {
          now = P.at(now);
          tmp += C.at(now);
          ans = max(ans, tmp);
        }
      }
    } else {
      for (auto a : fc) {
        long now = a;
        long tmp = 0;
        long cnt = K;
        if (K / n) {
          tmp = sum * (K / n - 1);
          cnt = K % n + n;
        }
        while (cnt--) {
          now = P.at(now);
          tmp += C.at(now);
          ans = max(ans, tmp);
        }
      }
    }
  }
  cout << ans << "\n";
}