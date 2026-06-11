#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=0;
  cin >> n;
  for(long i=1;i*i<=n-1;i++) {
    if((n-1)%i==0) {
      if(i!=1) ans++;
      if((n-1)/i!=i) ans++;
    }
  }
  for(long i=1;i*i<=n;i++) {
    if(n%i==0) {
      if(i!=1) {
        long a=n;
        while(a%i==0) a/=i;
        if(a%i==1) ans++;
      }
      if(n/i!=i) {
        long a=n;
        while(a%(n/i)==0) a/=(n/i);
        if(a%(n/i)==1) ans++;
      }
    }
  }
  
  cout << ans << endl;
}