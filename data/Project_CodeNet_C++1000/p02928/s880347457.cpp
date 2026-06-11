#include <bits/stdc++.h>
using namespace std;

const long mod = 1e9+7;

long sumto(int n){
  long r;
  if(n % 2)  r = (n+1)/2%mod * (n%mod) % mod;
  else  r = n/2% mod * ((n+1)%mod) % mod;
  return r;    
}

int main(){
  int n, k;  cin >> n >> k;
  vector<long> a(n);
  for(int i=0; i<n; i++)  cin >> a[i];

  vector<long> aftb(n, 0), bfrb(n, 0);
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++)
      if(a[j] < a[i])  bfrb[i]++;
    for(int j=i+1; j<n; j++)
      if(a[j] < a[i])  aftb[i]++;
  }

  long ans = 0;
  for(int i=0; i<n; i++)
    ans = (ans + sumto(k)*aftb[i]%mod + sumto(k-1)*bfrb[i]%mod) % mod;

  ans = (ans + mod) % mod;
  cout << ans << endl;
  
  return 0;
}
