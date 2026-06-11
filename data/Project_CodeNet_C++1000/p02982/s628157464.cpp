#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, d;
  cin >> n >> d;
  int a[n][d];
  rep(i,n){
    rep(j,d){
      cin >> a[i][j];
    }
  }
  
  double che;
  int ans = 0;
  rep(i,n){
    for(int j = i + 1; j < n; j++){
      che = 0;
      rep(k,d){
        che += pow(abs(a[i][k] - a[j][k]), 2);
      }
      che = sqrt(che);
      if(ceil(che == floor(che))) ans++;
    }
  }
         
  cout << ans << endl;
  
  return 0;
}