#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;

int const inf = INT_MAX / 2;

// Verified: https://atcoder.jp/contests/arc026/tasks/arc026_2
template<class T> vector<T> divisors(T x) {
  if (x <= 1) return {};
  vector<T> ret;
  int p = 1;
  while((ll)p * p <= x) {
    if(x % p == 0) {
      if (p > 1) ret.push_back(p);
      if (p != x/p) {
        ret.push_back(x/p);
      }
    }
    p ++;
  }
  return ret;
}

int main() {
  ll N; cin >> N;
  // N / K をしない場合；
  // N = 1 + q * K = 1 (mod K)
  // => K: N - 1 の約数の個数
  auto ans = divisors(N - 1).size();

  // N / K をする場合；
  // N の各約数について、Kの条件を満たすか
  for (auto K: divisors(N)) {
    auto n = N;
    while(n % K == 0) n /= K;
    ans += n % K == 1;
  }

  cout << ans << endl;
}
