#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> X(n);
  rep(i,n) cin >> X[i];
  int ans = INF;
  rep(i,100){
    int tot = 0;
    rep(j,n){
      tot += pow(X[j]-i,2);
    }
    if(tot<ans)ans = tot;
  }
  cout << ans << endl;
  return 0;
}
