#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  int k,a,b;
  cin >> k >> a >> b;
  for (int i = 1; i < b+1; i++) {
    if (a <= i * k && i * k <= b) {
      cout << "OK" << endl;
      return 0;
    }
  }
  cout << "NG" << endl;
}
