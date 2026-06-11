#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <int> d(N);
  rep(i,N) cin >> d[i];
  sort(all(d));
  int ans = d[N / 2] - d[N / 2 - 1];
  cout << ans << endl;
  return 0;
}
