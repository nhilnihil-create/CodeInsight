#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
const int biggg = 2000000000;
const long long bigggest = 1000000000000000000LL;
const double eps = .0000000001;

long long modpow(long long x, long long n) { 
  if (n == 0) return 1LL%mod; 
  long long u = modpow(x,n/2LL); 
 
  u = (long long)(u*u)%mod; 
  if (n%2LL == 1) u = (long long)(u*x)%mod; 
  return u;
}

int main ()
{
  prep();
  int n, k;
  cin >> n >> k;
  long long cnts[100001] = {0};
  for (int i=k; i>=1; i--){
      cnts[i] += modpow(k/i, n);
      cnts[i] = mymod(cnts[i]);
      for (int j=1; j<=sqrt(i); j++){
          if (i%j == 0 && j != i){
              cnts[j] -= cnts[i];
              if (j != i/j && i/j != i) cnts[i/j] -= cnts[i];
          }
      }
      
  }
  long long res = 0;
  for (int i=1; i<=k; i++){
      res += (cnts[i]*i)%mod;
      res %= mod;
  }
  cout << res;
  return 0;
}