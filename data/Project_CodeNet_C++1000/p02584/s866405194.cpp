#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x,k,d,cnt,ans;
  cin >> x >> k >> d;
  if(x < 0) x = -x;
  cnt = x / d;
  if(k > cnt){
    ans = abs(x - cnt * d - ((k-cnt) % 2) * d);
  }else{
    ans = x - k * d;
  }
  cout << ans << endl;
  return 0;
}