#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main() {
  string s,t;
  cin >> s >> t;
  int cnt = 0;
  rep(i,s.size()) {
    if (s.at(i) != t.at(i)) cnt++;
  }
  cout << cnt << endl;
}
