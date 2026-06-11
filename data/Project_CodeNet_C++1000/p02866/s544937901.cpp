#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 998244353;

int main(){
  int n;
  cin >> n;
  int t;
  cin >> t;
  if(t != 0) {
    puts("0");
    return 0;
  }
  --n;
  vector<int> d(n);
  rep(i, n) {
    cin >> d[i];
    if(d[i] == 0) {
      puts("0");
      return 0;
    }
  }

  ll ans = 1;
  sort(d.begin(), d.end());
  vector<int> cnt(100000);
  for(int i = 0; i < n; ++i) {
    cnt[d[i]]++;
  }
  cnt[0] = 1;
  for(int i = 1; i <= d[n - 1]; ++i) {
    rep(j, cnt[i]) {
      ans *= cnt[i - 1];
      ans %= mod;
    }
  }
  cout << ans << endl;
}