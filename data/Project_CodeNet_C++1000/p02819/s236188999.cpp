#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;

bool is_prime(long long N) {
  if (N == 1) return false;
  for (long long i = 2; i * i <= N; ++i) {
      if (N % i == 0) return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int x; cin>>x;
  
  while(true) {
    if(is_prime(x)) {
      cout<<x;
      return 0;
    } else {
      ++x;
    }
  }
}