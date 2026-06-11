#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> v(m);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    v[i].first = a;
    rep(j,b){
      int c;
      cin >> c;
      c --;
      v[i].second += (1 << c);
    }
  }
  vector<int> dp((1 << n),1001001001);
  dp[0] = 0;
  rep(i,(1 << n)){
    rep(j,m){
      int next = i | v[j].second;
      dp[next] = min(dp[next],dp[i]+v[j].first);
    }
  }
  if(dp[(1 << n) - 1] == 1001001001) cout << -1 << endl;
  else cout << dp[(1 << n) - 1] << endl;
}