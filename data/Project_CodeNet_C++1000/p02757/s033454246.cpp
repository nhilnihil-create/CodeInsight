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
long long mod = 998244353;
 
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

int main ()
{
  prep();
  int n, p;
  string s;
  cin >> n >> p >> s;
  long long cnt = 0;
  if (p == 2){
      // ends in even
      for (int i=0; i<n; i++){
          if ((s[i]-'0')%2 == 0) cnt += i+1;
      }
      cout << cnt;
      return 0;
  }else if (p == 5){
      // ends in 0 or 5
      for (int i=0; i<n; i++){
          if ((s[i]-'0')%5 == 0) cnt += i+1;
      }
      cout << cnt;
      return 0;
  }
  long long sums[n];
  long long curpow = 1;
  int freqs[p] = {0};
  for (int i=s.size()-1; i>=0; i--){
      sums[i] = curpow*(s[i]-'0');
      curpow *= 10;
      curpow %= p;
  }

  for (int i=0; i<n; i++) {
      if (i > 0) sums[i] += sums[i-1];
      sums[i] %= p;
      freqs[sums[i]]++;
  }
  
  long long cursum = 0;
  for (int i=0; i<s.size(); i++){
      cnt += freqs[cursum];
      freqs[sums[i]]--;
      cursum = sums[i];
  }
  cout << cnt;
  return 0;
}