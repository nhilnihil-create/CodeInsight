#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr uint64_t mod=1e9+7;

// a^n%mod
uint64_t bin_pow(uint64_t a,uint64_t n){
    uint64_t ans=1;
    while(n>0){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans%mod;
}

//a^(-1)(mod)=a^(mod-2)
uint64_t inv_mod(uint64_t a){
  return bin_pow(a,mod-2);
}

int main()
{
  uint64_t n;
  cin>>n;
  vector<uint64_t> a(n);
  for(auto&& e: a) 
  {
    cin>>e;
  }
  vector<uint64_t> vec(64,0);
  for (uint64_t i = 0; i < n; ++i)
  {
    for (uint64_t j = 0; j < 64; ++j)
    {
      vec[j]+=(a[i]>>j&1ULL);
    }
  }
  uint64_t ans=0;
  for (uint64_t i = 0; i < n; ++i)
  {
    for (uint64_t j = 0; j < 64; ++j)
    {
      if(a[i]>>j&1ULL)
      {
        ans+=(((n-vec[j])*(bin_pow(2, j)))%mod);
      }
      else ans+=(((vec[j])*(bin_pow(2,j)))%mod);
      ans%=mod;
    }

  }
  ans*=inv_mod(2);
  ans%=mod;
  cout<<ans<<endl;
}