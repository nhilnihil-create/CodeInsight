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

int main() {
  int N, M;
  cin>>N>>M;
  vector<int> even, odd;
  for(int i = M; i > 0; i--) {
    if(i % 2 ==	0) even.push_back(i);
    else odd.push_back(i);
  }
  int base = 1;
  REP(i, odd.size()) {
    cout << (i + base) << " " << (i + base + odd[i]) << endl;
  }
  base += odd[0] + 1;
  REP(i, even.size()) {
    cout << (i + base) << " " << (i + base + even[i]) << endl;
  }
  return 0;
}

