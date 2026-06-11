#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  
  
  long long ans=0;
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
      for(int s=1;s<=k;s++){
        ans += gcd(i, gcd(j, s) );
      }
    }
  }
  cout << ans << endl;
    
}
  
