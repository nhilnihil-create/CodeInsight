#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;

  if(n==1){
    cout << 0 << endl;
    return 0;
  }
  if(n==2){
    cout << 2 << endl;
    return 0;
  }

  long long u = 1;
  long long v = 1;
  long long x = 1;
  for (long long i = 0; i < n; i++)
  {
    u*=10;
    v*=9;
    x*=8;
    u%=1000000007;
    v%=1000000007;
    x%=1000000007;
  }  

  long long ans = u-2*v+x+1000000007*2;
  ans %= 1000000007;
  cout << ans << endl;
}