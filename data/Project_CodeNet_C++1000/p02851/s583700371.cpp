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
        lint n,k;
        cin >>n>>k; vector<lint> a(n);
        rep(i,n)cin >> a[i];
        lint b[n+1];
        lint c[n+1];
        b[0]=0;
        c[0]=0;
        rep(i,n){
            b[i+1]=a[i]+b[i];
            b[i+1]%=k;
            lint x=b[i+1]-(i+1)%k;
            x+=k;
            x%=k;
            c[i+1]=x;
            
          //  cout<<x<<endl;
        }
        lint ans=0;
        map<lint,lint> mp;
        lint g=min(k,n+1);
        rep(i,g){
            mp[c[i]]++;
        }
        for(auto x:mp){
            ans+=x.second*(x.second-1)/2;
        }
        rep(i,n+1-g){
            mp[c[i]]--;
            mp[c[i+g]]++;
            ans+=mp[c[i+g]]-1;
        }
       cout<<ans<<endl;
  }
          
  