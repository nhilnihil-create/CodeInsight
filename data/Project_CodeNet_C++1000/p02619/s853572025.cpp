#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
  int D, ans = 0, check = 0, count = 0 ;
  int C[27] ;
  cin >> D ;
  int S[27][D+1], choice[D+1] = {}, history[27] = {} ;
  for(int i=1;i<27;i++) cin >> C[i] ;
  for(int i=1;i<(D+1);i++){
    for(int j=1;j<27;j++){
      cin >> S[j][i] ;
    }
  }
  for(int date=1;date<(D+1);date++){
    cin >> choice[date] ;
    history[choice[date]] = date ;
    ans += S[choice[date]][date] ;
    for(int i=1;i<27;i++){
      ans -= C[i] * ( date - history[i]) ;
    }
    cout << ans << endl ;
  }
  return 0 ;
}  