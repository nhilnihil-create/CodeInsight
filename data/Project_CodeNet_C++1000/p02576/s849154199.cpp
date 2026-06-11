#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x,t;
  cin >> n >> x >> t;

  int amari; //一杯に焼いた場合の端数
  amari = n % x;

  int a;//一杯に焼いた場合に焼く回数
  a = (n - amari) / x;
  int ans =0;
  ans = a * t;//一杯に焼いた場合にかかる時間

  if (amari == 0){
    cout << ans << endl;
  }
  else{
    ans = ans + t;
    cout << ans << endl;
  }
}