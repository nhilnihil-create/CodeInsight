#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m) {
    int x;
    cin >> x;
    n -= x;
  }
  if (n < 0) cout << -1 << endl;
  else cout << n << endl;
}
