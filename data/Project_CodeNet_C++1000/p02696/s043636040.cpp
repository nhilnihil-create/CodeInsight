#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }

void inline TorF(bool tf, const string &trueMessage, const string &falseMessage) { 
  cout << (tf ? trueMessage : falseMessage) << endl;
}
void inline YESNO(bool tf) { TorF(tf, "YES", "NO"); }
void inline YesNo(bool tf) { TorF(tf, "Yes", "No"); }

inline ll f(ll A, ll B, ll X)  {
  return (A*X/B) - A*(X/B);
}

int main() {
  ll A, B, N; cin>>A>>B>>N;
  ll ans = f(A, B, N);
  if(B-1LL <= N) {
    ll work = f(A, B, B-1);
    ans = max(ans, work);
  }
  cout << ans << endl;
  return 0;
}
