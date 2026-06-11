#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int func(int k){
  int a,b,x;
  a = k%10;
  b = k/10;
  x = a*b;
  return x;
}

int main() {
  int m,d;
  cin >> m >> d;
  int ans = 0;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=d;j++){
      if(i == func(j) && j%10 >=2 && j/10 >= 2){
        ans++;
      }
    }
  }
  cout << ans << endl;  
  
  return 0;
}
