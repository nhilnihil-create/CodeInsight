#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
  int N; cin >> N;
  vector<int> x;
  ll L = INF, R = 0; 
  rep(i,N) {
    ll a;
    cin >> a;
    x.push_back(a);
    L = min(L,a);
    R = max(R,a);
  }
  ll ans = INF;
  for(int i = L; i <= R; i++){
    ll sum = 0;
    rep(j,N){
      sum += (x[j] - i)*(x[j] - i);
    }
    ans = min(ans,sum);
  }

  cout << ans << endl;

	return 0;
}

