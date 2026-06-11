#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];

  ll ans = 0;
  rep(i,n){
    for(int j = i+1;j<n;j++){
      ans += d[i]*d[j];
    }
  }

  cout << ans << endl;
  
  return 0;
}
