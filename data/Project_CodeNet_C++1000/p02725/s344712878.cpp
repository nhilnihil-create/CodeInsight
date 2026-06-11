#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int K, N;
  cin >> K >> N;
  int A[N];
  rep(i,N)cin >> A[i];
  int D[N];
  rep(i,N-1){
    D[i] = A[i+1] - A[i];
  }
  D[N-1] = (K - A[N-1]) + A[0];
  int l = 0;
  rep(i,N) l = max(l,D[i]);
  int ans = K - l;
  cout << ans << endl;


	return 0;
}
