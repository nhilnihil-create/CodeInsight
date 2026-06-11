#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int d1 = (c + b - 1) / b;
  int d2 = (a + d - 1) / d;
  if (d1 <= d2) cout << "Yes" << endl;
  else cout << "No" << endl;
}
