#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) v.begin(), v.end()
#define ll long long
ll INF = 1e9;
ll mod = 1e9+7;

ll dp[10001];
int main() {
  int a,b,c; cin >> a >> b >> c;
  cout << c-min(c,a-b) << endl;
}