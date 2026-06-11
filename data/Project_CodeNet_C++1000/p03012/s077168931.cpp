#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int w[n];
  rep(i,n){cin >> w[i];}
  
  int sum1 = 0;
  int sum2 = 0;
  int ans = 1e9;
  rep(i,n){
    rep(j,n){
      if(j <= i){
        sum1 += w[j];
      }else{
        sum2 += w[j];
      }//else
    }//rep
    if(abs(sum1 - sum2) < ans){
      ans = abs(sum1 - sum2);
    }//if
    sum1 = 0;
    sum2 = 0;
  }//rep
  
  cout << ans << endl;

}