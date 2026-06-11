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

int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  int ans = 0;
  rep(i, N) {
    ans += S[i] == 'L' && i && S[i - 1] == 'L';
    ans += S[i] == 'R' && i + 1 < N && S[i + 1] == 'R';
  }
  string T = S;
  T.erase(unique(T.begin(), T.end()), T.end());
  int swap_count = 0;
  REP(i, 1, T.size() - 1) {
    if (swap_count + 1 <= K) {
      T[i] = T[i] == 'L' ? 'R' : 'L';
      swap_count++;
      i++;
      ans += 2;
    }
  }
  T.erase(unique(T.begin(), T.end()), T.end());
  if (T.size() > 1 && swap_count + 1 <= K) {
    T[0] = T[0] == 'L' ? 'R' : 'L';
    ans++;
    swap_count++;
  }
  T.erase(unique(T.begin(), T.end()), T.end());
  if (T.size() > 1 && swap_count + 1 <= K) {
    T.back() = T.back() == 'L' ? 'R' : 'L';
    ans++;
  }
  cout << ans << "\n";
}
