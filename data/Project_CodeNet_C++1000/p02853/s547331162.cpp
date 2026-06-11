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

int f(int n) {
  if(n == 1) return 300000;
  if(n == 2) return 200000;
  if(n == 3) return 100000;
  return 0;
}


int main() {
  int ans = 0;
  int X, Y; cin>>X>>Y;
  ans += f(X) + f(Y);
  if(X == 1 && Y == 1) ans += 400000;
  cout << ans << endl;
  return 0;
}
