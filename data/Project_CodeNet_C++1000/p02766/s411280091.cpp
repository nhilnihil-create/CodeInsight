#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  
  int ans;
  for (int i=1 ; ; i++){
    int keta = pow(k, i);
    if (n/keta == 0){
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;
}