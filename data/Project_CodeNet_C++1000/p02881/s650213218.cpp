#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  
  long ans;
  
  long m = sqrt(n)/1;
  
  for(long i=m; i>0; i--){
    if(n%i==0){
      long j = n/i;
      ans = i + j - 2;
      cout << ans << endl;
      return 0;
    }
  }
}
