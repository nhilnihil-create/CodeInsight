#include <bits/stdc++.h>
using namespace std;

int64_t powmod(int x, int pow)
{
  int64_t total = 1;
  while(pow > 0)
  {
    total = total * x % 1000000007;
    pow--;
  }
  return total;
}

int main()
{
  int N;
  cin >> N;
  
  int mod = 1000000007;
  
  if(N == 1){cout << "0" << endl;}
  else
  {
    int64_t T = 0;
    T += (powmod(10,N) - powmod(9,N)) % mod;
    if(T < 0) T += mod;
    T -= powmod(9,N);
    if(T < 0) T += mod;
    T = T % mod;
    T += powmod(8,N);
    if(T < 0) T += mod;
    T = T % mod;
    cout << T << endl;
  }
}