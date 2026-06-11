#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n;
vector<int> vec;
bool check(int a, int b, int c) {
  bool va = a < b + c;
  bool vb = b < c + a;
  bool vc = c < a + b;
  return va && vb && vc;
}

int main()
{
  cin >> n;
  vec.resize(n);
  rep(i,n) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  int ans = 0;
  rep(i, n)reps(j, i+1, n) {
    auto it = lower_bound(vec.begin()+ j + 1, vec.end(), vec.at(j) + vec.at(i));
    int d = it - (vec.begin() + j) - 1;
    ans += d;
  }
  cout << ans << endl;
  return 0;
}