#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  long int n, k;
  cin >> n >> k;
  if(k>=n){
    cout << 0 << endl;
    return 0;
  }
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  sort(h.begin(),h.end());
  long long ans=0;
  rep(i,n-k){
    ans += h[i];
  }
  cout << ans << endl;
  return 0;
}
