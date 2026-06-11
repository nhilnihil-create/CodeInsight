#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  ll N, A, B; cin >> N >> A >> B;
  ll SUM = A + B;
  ll ans = (N / SUM) * A;
  ll amari = N%SUM;
  ans += min(amari,A);
  cout << ans << endl;  


	return 0;
}

