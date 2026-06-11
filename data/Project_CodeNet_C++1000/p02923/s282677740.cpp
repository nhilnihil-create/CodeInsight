#include <bits/stdc++.h>
using namespace std;



int main() {
  long H;
  int N;
  int ans = 0;
  int t = 0;
  
  cin >> N >> H;
  for(int i=0;i<N-1;++i){
    long h; cin >> h;
    if(h <= H){
      t++;
    }else{
      if(t > ans){
        ans = t;
      }
      t = 0;
    }
    H = h;
  }

  if(t > ans){
    ans = t;
  }
  cout << ans << endl;
  return 0;
}
