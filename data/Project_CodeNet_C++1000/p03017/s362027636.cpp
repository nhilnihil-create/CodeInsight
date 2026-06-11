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

int N, A, B, C, D;
string S;

bool solve1() {
  vector<bool> dpA(N);
  {
    dpA[A] = 1;
    REP(i, 1, N) {
      if (S[i] == '#') continue;
      dpA[i] = dpA[i] || dpA[i - 1];
      if (i - 2 >= 0) dpA[i] = dpA[i] || dpA[i - 2];
    }
  }
  vector<bool> dpB(N);
  {
    dpB[B] = 1;
    REP(i, 1, N) {
      if (S[i] == '#') continue;
      dpB[i] = dpB[i] || dpB[i - 1];
      if (i - 2 >= 0) dpB[i] = dpB[i] || dpB[i - 2];
    }
  }
  return dpA[C] && dpB[D];
}

bool solve2() {
  if (C < D) {
    return 1;
  }

  bool flag = 0;
  REP(i, B - 1, D) {
    if (i + 2 >= N) break;
    if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
      flag = 1;
    }
  }
  return flag;
}

int main() {
  cin >> N >> A >> B >> C >> D >> S;
  A--, B--, C--, D--;
  cout << (solve2() && solve1() ? "Yes\n" : "No\n");
}
