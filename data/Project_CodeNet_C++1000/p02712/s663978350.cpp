#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
  int n;
  cin >> n;
  long cnt = 0;
  
  rep(i,n+1){
  	if(i % 3 != 0 && i % 5 != 0 ){
      cnt += i;
    }
  }
  
  cout << cnt << endl;
  
}