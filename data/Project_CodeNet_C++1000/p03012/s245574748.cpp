#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> w(n);
  rep(i,n) cin >> w[i];

  int sum = 0;
  rep(i,n) sum+=w[i];
  
  int ans = INF;
  int s1 = sum,s2 = 0;
  rep(i,n){    
    s1-=w[i];
    s2+=w[i];
    ans = min(ans,abs(s1-s2));
  }

  cout << ans << endl;
  
  return 0;
}
