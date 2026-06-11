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

int const MOD = 998244353;

int main() {
  int N; cin >> N;
  vector<int> D(N);
  map<int, int> C;
  int max = -1;
  rep(i, N) {
    cin >> D[i];
    C[D[i]]++;
    max = std::max(max, D[i]);
  }
  if (D[0] || C[0] != 1) {
    cout << "0\n";
    return 0;
  }
  rep(i, max) if (!C[D[i]]) {
    cout << "0\n";
    return 0;
  }

  ll ans = 1;
  REP(i, 1, max + 1) rep(_, C[i]) (ans *= C[i - 1]) %= MOD;
  cout << ans << endl;
}
