#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, K;
  cin >> N >> K;
  vl H(N);
  rep(i, N) cin >> H[i];

  if(N <= K){
    cout << 0 << "\n";
    return 0;
  }

  stable_sort(H.begin(), H.end(), greater<ll>());

  ll ans = 0;

  rep2(i, K, N) ans += H[i];

  cout << ans << "\n";
  
  return 0;
}
