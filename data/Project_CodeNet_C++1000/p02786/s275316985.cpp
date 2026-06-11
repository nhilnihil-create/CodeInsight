#include<bits/stdc++.h>
using namespace std;

int f_rec(int cnt){
  return 2 * f_rec(cnt / 2) + 1;
}


int main(){
  int64_t h, ans=1;
  cin >> h;
  while(h > 0){
    ans *= 2;
    h /= 2;
  }
  cout << ans-1 << endl;
  return 0;
}
