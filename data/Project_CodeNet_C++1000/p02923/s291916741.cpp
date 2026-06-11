#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> h(n); rep(i,n) cin >> h[i];

  int ans = 0;
  int tmp = 0;
  rep(i,n-1){
    if(h[i]>=h[i+1]) tmp++;
    else tmp = 0;
    ans = max(ans,tmp);
  }

  cout << ans << endl;
  
  return 0;
}
