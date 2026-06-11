#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  const int N = 1000000;
  vector<int> a(N, 1);
  a[0] = a[1] = 0;
  for (int i = 2; i < N; i++) if (a[i])
  for (int j = i * 2; j < N; j += i) a[j] = 0;
  int n; cin >> n;
  while (!a[n]) n++;
  cout << n << '\n';
}
