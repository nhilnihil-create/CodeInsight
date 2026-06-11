#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(lint (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
 
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    } 

  int main(){      
     string s;
     lint n,p;

     cin>>n>>p>>s;
     reverse(all(s));
     lint a[n];
     lint mul=1;
    lint b[n+1];
     lint ans=0;
     map<lint,lint> mp;
     if(p==2){
         rep(i,n){
             lint x=s[i]-'0';
             if(x%2==0)ans+=n-i;
         }
     }else if(p==5){
          rep(i,n){
             lint x=s[i]-'0';
             if(x%5==0)ans+=n-i;
         }
     }else{
     rep(i,n){
         lint x=s[i]-'0';
         x*=mul;
         x%=p;
         a[i]=x;
         mul*=10;
         mul%=p;
     }
     b[0]=0;
     mp[0]++;
     rep(i,n){
         b[i+1]=b[i]+a[i];
         b[i+1]%=p;
         mp[b[i+1]]++;
     }
     for(auto x:mp){
         ans+=x.second*(x.second-1)/2;
     }}
     cout<<ans<<endl;
          }
  
     
