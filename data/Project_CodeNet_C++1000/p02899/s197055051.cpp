#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int n; cin >> n;
  vector<int> A(n);
  rep(i,n) cin >> A[i];
  vector<int> ans(n);
  rep(i,n){
    ans[A[i] -1] = i+1;
  }

  rep(i,n) cout << ans[i] << endl;

	return 0;
}

