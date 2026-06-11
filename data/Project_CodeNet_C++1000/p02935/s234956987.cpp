#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N;cin >> N;
  vector<int> v(N);
  rep(i,N)cin >> v[i];
  sort(v.begin(),v.end());

	double ans = v[0];
  for(int i = 1; i < N; i++){
    ans = (ans + v[i])/2;
  }
  cout << fixed << setprecision(15) << ans << endl;

	return 0;
}
