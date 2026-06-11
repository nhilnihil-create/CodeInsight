#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;


int main(){
  ll l, r;
  int ans;
  cin >> l >> r;
  ll la = l/2019, lb = l%2019, ra = r/2019, rb = r%2019;
  if(ra - la >0){
    ans = 0;
  }
  else{
    ans = 2018;
    for(int i = lb; i<rb; i++){
      for(int j = i+1; j<rb+1; j++){
        ll ans_temp = (i*j)%2019;
        if (ans_temp<ans) ans = ans_temp;
      }
    }
  }
  cout << ans;

  }
