#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int modexp(int x, int y)
{
	int mod = MOD,res = 1;
    x = (x % mod + mod) % mod;
    while(y)
    {
        if(y & 1)res = (res*x) % mod;
        y >>= 1;
        x = ((x%mod)*(x%mod)) % mod;
    }
    return res; 
}
int modInverse(int x)
{
	return modexp(x,MOD-2)%MOD;
}

int choose(int n,int r)
{
  const int mod = MOD;
  int a = 1, b = 1;
  
 for(int i = 0; i < r; i++)
 { //calculate factorial
   a = ((a%mod)*((n-i)%mod))%mod;  //calculate X
   b = ((b%mod)*((1+i)%mod))%mod;	//calculate Y
 }
  
  int ans = ((a%mod)*((modInverse(b)%mod)%mod))%mod;
  
  return ans%mod;
}
  
int32_t main()
{
  
  int n,a,b;
  cin >> n >> a >> b ;
  //total ways of making the bouquet become 2^n -1
  int ans = (modexp(2,n)%MOD - 1)%MOD;
  //subtrct ways of nCa + nCb
  //factorial or X/Y under mod, can be found by modular inverse arithmetic
  //This is an application of fermat's little theorem
  //X/Y%mod == X%mod * Y^(mod-2)%mod)%mod, where mod must be a prime number
  int ans1 = (choose(n,a)%MOD + choose(n,b)%MOD)%MOD;
  ans = (ans%MOD- ans1%MOD)%MOD;
  
  cout << (ans + MOD)%MOD;
  
  
  
}
