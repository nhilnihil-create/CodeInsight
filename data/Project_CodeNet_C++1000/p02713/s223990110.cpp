#include <bits/stdc++.h>
using namespace std;
int main(){
  int K;
  int ans=0;
  cin>>K;
  for (int i=1; i<=K; i++){
    for (int j=1; j<=K; j++){
      for (int k=1; k<=K; k++){
        ans += gcd(i, gcd(j,k));
      }
    }
  }
  cout << ans << endl;
  return 0;
}