#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  ll N, K;
  cin >> N >> K;

  vector<ll> H(N);
  for (ll i=0 ; i<N; i++){
    cin >> H[i];
  }

  sort(H.begin(), H.end(),greater<int>());

  ll ans=0;

  for (ll i=K ; i<N; i++){
    ans+=H[i];
  }
  cout << ans << endl;
  
  return 0;
}
