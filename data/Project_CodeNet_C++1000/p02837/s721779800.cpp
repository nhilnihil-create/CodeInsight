#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
using ll=long long;


// vector<vector<int>> a[15][15];

int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, -1));
  rep(i,n){
    int m;
    cin >> m;
    rep(j,m){
      int x, y;
      cin >> x >>y;
      x--;
      a[i][x] =y;
    }
  }
  
  int ans =0;
  for (int bit = 0; bit < (1<<n); ++bit) {
    int count =0;
    vector<int> check(n,0);
    for (int i = 0; i < n; ++i) {
      if (bit & (1<<i)) {
        count +=1;
        check[i]=1;
      }
    }
    bool condition=true;
    rep(i,n){
      if(check[i]==1){
        rep(j,n) {
          if(a[i][j]==1 && check[j]==0) condition=false;
          if(a[i][j]==0 && check[j]==1) condition=false;
        }
      }
    }
    if(condition) ans = max(ans,count);
  }
  cout << ans << endl;
}