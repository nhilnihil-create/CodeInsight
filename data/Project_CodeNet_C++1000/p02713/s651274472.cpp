#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)

int keisan(int a, int b){
  int c, d;
  while(d != 0){
    c = b;
    d = a % b;
    if(d == 0){
      break;
      }
    a = c, b = d;
  }
  return b;
}

int main(void){
  int k;
  cin >> k;
  long cnt = 0;
  int a, b;
  
  rep(i, k+1){
  	rep(j, k+1){
  	  a = keisan(i, j);
      rep(l, k+1){
        b = keisan(a, l);
        cnt += b;
      }
    }
  }
  cout << cnt << endl;
}