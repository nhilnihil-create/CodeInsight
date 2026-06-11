#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int f(int n) {
  int a = 0;
  while(n) {
    a = n;
    n /= 10;
  }
  return a;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> vec(10, vector<int>(10, 0));

  for (int i = 1; i <= n; i++) {
    int a = i % 10;
    int b = f(i);
    vec.at(a).at(b)++;
  }
  ll ans = 0;
  reps(i, 1, 10) {
    reps(j, 1, 10) {
      ans += vec.at(i).at(j) * vec.at(j).at(i);
    }
  }
  cout << ans << endl;
  return 0;
}