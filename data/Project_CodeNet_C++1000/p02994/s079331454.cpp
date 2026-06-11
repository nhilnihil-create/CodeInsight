#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,l; cin >> n >> l;
  vector<int> taste(n);
  for(int i = 1;i<=n;i++) taste[i-1] = l+i-1;
  int max = 0;
  for(int i = 1;i<=n;i++) max+=taste[i-1];

  int ans = INF;
  for(int i = 1;i<=n;i++){
    int t = max-taste[i-1];
    if(abs(max-t) < abs(ans-max)) ans = t;
  }

  cout << ans << endl;
  
  return 0;
}
