#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> vec(n, vector<int>(d));
  rep(i,n){
    rep(j,d){
      cin >> vec[i][j];
    }
  }
  int ans;
  ans = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = i + 1; j < n; j++){
      int a = 0;
      rep(k,d){
        a += (vec[i][k] - vec[j][k]) * (vec[i][k] - vec[j][k]);
      }
      
      for(int l = 0; l < a + 1; l++){
        if(l * l == a){
          ans = ans + 1;
        }
      }
    }
  }
  cout << ans;
}