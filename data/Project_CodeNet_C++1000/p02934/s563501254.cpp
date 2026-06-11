#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {

  int N; cin >> N;
  int A[N];
  rep(i,N){
    cin >> A[i];
  }
  double ans = 0;
  rep(i,N){
    ans += (double)1 / A[i];
  }
  ans = (double)1 / ans;
  cout << fixed << setprecision(15) << ans << endl;
	return 0;
}

