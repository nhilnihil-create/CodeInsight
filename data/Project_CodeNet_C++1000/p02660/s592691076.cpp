#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;
  cin >> n;
  long long con=0;
  long long ans=0;
  for(long long a=2;a*a<=n;++a){
    if(n%a!=0) continue;
    con =0;
    while(n%a==0){
      con++;
      n/=a;
      
      }
      for(int j=1;con >= j;j++){
        con -= j;
        ans++;
      
    }
    
  }
  if(n >1) ans++;
  cout << ans << endl;
  
}