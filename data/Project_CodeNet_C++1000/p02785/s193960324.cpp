#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N, K; cin >> N >> K;
  vector<int> H(N,0);
  rep(i,N) cin >> H[i];
  sort(H.begin(), H.end());
  reverse(H.begin(), H.end());
  ll attack = 0;
  for(int i = K; i < N; i++){
    attack += H[i];
  }

  cout << attack << endl;
	return 0;
}

