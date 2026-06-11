#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  ll x; cin >> x;
  ll p = 100, step = 0;
  while (p < x) {
    p += p / 100;
    step++;
  }
  cout << step << endl;
  return 0;
}
