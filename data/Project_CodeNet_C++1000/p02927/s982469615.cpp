#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int digit(int N){
  int d1 = N%10;
  int d10 = N/10;
  int pro = 1;
  if(d1>=2 && d10>=2) {
    pro = d1*d10;
  } else {
    pro = 0;
  }
  return pro;
}

int main(){
  int m,d;
  cin >>m >>d;
  int cnt = 0;
  for(int i = 1; i<=d; i++){
    int pro = digit(i);
    for(int j = 2; j<=m; j++){
      if(j==pro) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}