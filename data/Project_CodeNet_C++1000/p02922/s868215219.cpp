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
#define PI 3.14159265358979323846264338327950L


using Graph = vector<vector<int>>;

signed main() {
  int a,b;
  cin >> a >> b;
  int cnt = 1;
  int ans = 0;
  while (cnt<b) {
    cnt += a-1;
    ans++;
  }
  cout << ans << endl;
}