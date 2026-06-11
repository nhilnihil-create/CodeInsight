/* D - Div Game */

#include <bits/stdc++.h>
using namespace std;

int main(void){
  long long N, num;
  int ans = 0;
  cin >> N;
  num = N;
  for(long long p = 2; p <= sqrt(num); p++){
    int cnt = 0;
    while(num % p == 0){
      num /= p;
      cnt++;
    }
    for(int i = 1; ; i++){
      if(cnt - i >= 0){
        cnt -= i;
        ans++;
      }else{
        break;
      }
    }
  }
  // num > 1のときにp <= sqrt(num)を満たすpが存在なければnumは素数
  if(num > 1) ans++;
  cout << ans << endl;
}