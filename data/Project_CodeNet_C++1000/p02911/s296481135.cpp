#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,k,q; cin >> n >> k >> q;
  vector<int> a(q); rep(i,q) cin >> a[i];
  vector<int> score(n+1,k);

  rep(i,q)
    score[a[i]]++;

  for(int i = 1;i<=n;i++){
    score[i] -= q;
    if(score[i]<=0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  
  /*rep(i,q){
    for(int j = 1;j<=n;j++){
      if(j==a[i]) continue;
      score[j]--;
    }
  }
  for(int i = 1;i<=n;i++){
    if(score[i]<=0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  */
  return 0;
}
