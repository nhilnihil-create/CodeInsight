#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}

int main(){
  int k;
  cin >> k;
  long long ans = 0;
  for(int i = 0; i < k; i++){
    for(int j = 0; j < k; j++){
      for(int l = 0; l < k; l++){
        ans += gcd(gcd(i + 1, j + 1), l + 1);
      }
    }
  }
  cout << ans << endl;
}