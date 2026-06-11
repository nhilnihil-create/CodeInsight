#include <bits/stdc++.h>
using namespace std;

long mod = 998244353;

long modpow(long a, long n){
  long r = 1;
  while(n){
    if(n & 1)  r = r * a % mod;
    a = a * a % mod;
    n = n >> 1;
  }
  return r;
}

int main(){
  int n, d;  cin >> n >> d;
  vector<long> table(n, 0);
  bool nothing = (d != 0), zero = false;
  for(int i=1; i<n; i++){
    cin >> d;
    table[d]++;
  }
  if(table[0])  nothing = true;
  long ans = 1;
  for(int i=1; i<n-1; i++){
    if(table[i]>0 && zero)  nothing = true;
    if(table[i] == 0)  zero = true;
    if(table[i] == 1)  continue;
    ans = (ans * modpow(table[i], table[i+1])) % mod;
  }

  if(nothing || (n==1 && table[0]==0))  ans = 0;
  cout << ans << endl;

  return 0;
}
