#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
// #define sort(a) sort(all(a))
using P = pair<int, int>;
using ll = long long;
using ld = long double;
typedef vector<int> vi;
int dx[4] = { 0, 1, 0,-1 };
int dy[4] = { 1, 0,-1, 0 };
const ll MOD = 1000000007;

signed main() {
  int a,b;
  cin >> a >> b;
  if(a<b) {
    for (int i = 0; i < b; i++) cout << a;
  } else {
    for (int i = 0; i < a; i++) cout << b;
  }
  cout << endl;
  return 0;
}