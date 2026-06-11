#include <bits/stdc++.h>
using namespace std;
 
int main() {
  const int Mod = 1000000000+7;
  int n;
  cin >> n;
  long long a[3*100000+10];
  long long b[65];
  
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int j=0; j<62; j++){
    b[j]=0;
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<62; j++){
      b[j] += ((a[i] >> j) & 1);
    }
  }
  long long ans = 0;
  long long p = 1;
  for(int j=0; j<62; j++){
    long long x = b[j]*(n-b[j])%Mod;
    ans = (ans + p*x)%Mod;
    //cout << p << " " << b[j] << " " << ans << endl; 
    p = (p*2)%Mod;
  }
  cout << ans;
  

}
 
