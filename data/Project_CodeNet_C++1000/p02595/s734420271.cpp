#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main() {
  int n,d;
  cin >> n >> d;
  int cnt = 0;
  rep(i,n) {
    int x,y;
    cin >> x >> y;
    double total = pow(pow(x,2) + pow(y,2),0.5);
    if (total <= d) cnt++;
  }
  cout << cnt << endl;
}
