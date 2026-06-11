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
/*
  a[0] ^ a[2] = a[1];
  a[1] ^ a[3] = a[2];

      a[0] ^ a[2] ^ a[1] ^ a[3] = a[1] ^ a[2];
  <=> a[0] ^ a[1] ^ a[2] ^ a[3] = a[1] ^ a[2];

   a[0] ^ a[1] ^ a[2] ^ a[3] = a[1] ^ a[2];
   a[2] ^ a[3] ^ a[4] ^ a[5] = a[3] ^ a[4];
   ...
^) a[n-2] ^ a[n-1] ^ a[0] ^ a[1] = a[n-1] ^ a[0]
-------------------------------------------------
   0 = a[0] ^ a[1] ^ ... ^ a[n-1]
*/
  int N; cin >> N;
  int s = 0;
  rep(i, N) {
    int a; cin >> a;
    s ^= a;
  }
  cout << (s == 0 ? "Yes\n" : "No\n");
}
