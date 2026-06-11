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

int const MOD = 1e9+7;

namespace math {

constexpr int MaxComb = 2010;

struct Combination {

  long long comb_[MaxComb][MaxComb];
    
  Combination() {
    rep(i, MaxComb) {
      comb_[i][0] = 1;
      REP(j, 1, i+1) {
        comb_[i][j] = comb_[i-1][j-1] + comb_[i-1][j];
        comb_[i][j] %= MOD;
      }
    }
  }

  long long comb(int n, int r) const { return comb_[n][r]; }

};

}

math::Combination comb;

int main() {
  int N, K; cin >> N >> K;
  REP(n_blue_group, 1, K + 1) {
    ll pat = comb.comb(N - K + 1, n_blue_group);
    (pat *= comb.comb(K - 1, n_blue_group - 1)) %= MOD;
    cout << pat << "\n";
  }
}