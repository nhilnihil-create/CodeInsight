#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  int n,k;
  cin >> n >> k;
  std::vector<int> vec(n,0);
  rep(i,k) {
    int d;
    cin >> d;
    rep(j,d) {
      int x;
      cin >> x;
      x--;
      vec.at(x) = 1;
    }
  }
  int cnt = 0;
  rep(i,n) {
    if (vec.at(i) == 0) cnt++;
  }
  cout << cnt << endl;
}
