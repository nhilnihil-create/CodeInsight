#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t1, t2;
  ll a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if (a1*t1 < b1*t1 && a1*t1+a2*t2 < b1*t1+b2*t2) { //追い越しが発生しない
    cout << 0 << endl;
    return 0;
  }
  if (a1*t1 > b1*t1 && a1*t1+a2*t2 > b1*t1+b2*t2) {
    cout << 0 << endl;
    return 0;
  }
  ll d1 = a1*t1+a2*t2, d2 = b1*t1+b2*t2;
  ll dist = abs(d1-d2);
  if (!dist) {
    cout << "infinity" << endl;
    return 0;
  }
  ll n = abs(a1-b1)*t1/dist; //このnはまだ追い越し発生条件を満たしているので、あと1ターン残っている
  ll ans = n*2-1; //最初のターンは並んでスタートするので1回しか追い越しが発生しない
  if (dist*n+min(a1, b1)*t1 < max(a1, b1)*t1) //この後1回完全に追い越す場合、追い越されも発生するので+2
    ans += 2;
  else //追い越すのではなく並ぶパターンは+1
    ans++;
  cout << ans << endl;
  return 0;
}