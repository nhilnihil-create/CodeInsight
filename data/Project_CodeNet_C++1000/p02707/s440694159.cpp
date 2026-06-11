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

int m[200010];
int a;
signed main() {
  int N;cin >>N;
  for (int i = 1; i < N; i++) {
    cin >> a;
    m[a-1]++;
  }
  for (int i = 0; i < N; i++) cout << m[i] << endl;
  return 0;
}