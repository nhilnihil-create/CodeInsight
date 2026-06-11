#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N,K; cin >> N>> K;
  int ans = 0;
  rep(i,N){
    int h;
    cin >> h;
    if (h >= K) ans++;
  }

  cout << ans << endl;

	return 0;
}

