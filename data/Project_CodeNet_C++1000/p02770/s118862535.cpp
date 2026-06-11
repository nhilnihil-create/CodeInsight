#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

int main() {
  i64 K, Q;
  cin >> K >> Q;
  vector<i64> D(K);
  rep(i,0,K) {
    cin >> D[i];
  }
  rep(q,0,Q) {
    i64 n, x, m;
    cin >> n >> x >> m;
    i64 now = 0;
    i64 sum = 0;
    i64 ans = 0;
    rep(i,0,K) {
      i64 next = now + D[i];
      i64 diff = (next - now) % m;

      if(n % K == 0) {
        if(i != K - 1) {
          sum += diff * (n / K);
        }
        else {
          sum += diff * (n / K - 1);
        }
      }
      else if(i + 1 < n % K) {
        sum += diff * (n / K + 1);
      }
      else {
        sum += diff * (n / K);
      }
      if(diff == 0) {
        if(n % K == 0) {
          if(i != K - 1) {
            ans += 1 * (n / K);
          }
          else {
            ans += 1 * (n / K - 1);
          }
        }
        else if(i + 1 < n % K) {
          ans += 1 * (n / K + 1);
        }
        else {
          ans += 1 * (n / K);
        }
      }
      now = next;
    }
    sum += x % m;
    cout << n - ((sum / m) + ans) - 1 << endl;
  }
}
