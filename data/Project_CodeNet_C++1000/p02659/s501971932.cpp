#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

int ctoi(char c) {if (c >= '0' && c <= '9') {return c - '0';}return 0;}

int main() {
  ll a;
  string b;
  cin >> a >> b;
  a = a * ctoi(b[0]) * 100 + a * ctoi(b[2]) * 10 + a * ctoi(b[3]);
  cout << a / 100 << endl;
  return 0;
}