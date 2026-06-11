#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pb push_back
#define mp  make_pair
#define loop(a,n) for(long long i=a;i<n;i++)
#define vil vector<long long int>
#define vi vector<int>
#define sz(v) v.size()
#define setbits(x)          __builtin_popcountll(x)
#define ff first
#define ss second
using namespace std;


ll gcd(ll a, ll b) {
  if (a == 0)return b;
  return gcd(b % a, a);
}
bool isperfect(ll n) {
  ll y = sqrt(n);
  if (n % y == 0 && y * y == n)return true;
  return false;
}
bool comp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) return a.second>b.second;
  return a.first < b.first;
}
 ll powi(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)ans = (ans * a);
    b = b >> 1;
    a = (a * a);
  }
  return ans;
}
bool isprime(ll n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}
bool prime[10000000];
void seive() {

  prime[1] = true;
  for (int i = 2; i * i < 10000000; i++) {

    if (prime[i])continue;
    for (int j = i * i; j < 10000000; j += i) {
      prime[j] = true;
    }

  }
}

// unsigned long long power(unsigned long long x, 
//                          int y, int p) 
// { 
//     unsigned long long res = 1; // Initialize result 
  
//     x = x % p; // Update x if it is more than or 
//     // equal to p 
  
//     while (y > 0) { 
//         // If y is odd, multiply x with result 
//         if (y & 1) 
//             res = (res * x) % p; 
  
//         // y must be even now 
//         y = y >> 1; // y = y/2 
//         x = (x * x) % p; 
//     } 
//     return res; 
// } 
  
// // Returns n^(-1) mod p 
// unsigned long long modInverse(unsigned long long n, int p) 
// { 
//     return power(n, p - 2, p); 
// } 
  
// // Returns nCr % p using Fermat's little 
// // theorem. 
// unsigned long long nCrModPFermat(unsigned long long n, 
//                                  int r, int p) 
// { 
//     // Base case 
//     if (r == 0) 
//         return 1; 
  
//     // Fill factorial array so that we 
//     // can find all factorial of r, n 
//     // and n-r 
//     unsigned long long fac[n + 1]; 
//     fac[0] = 1; 
//     for (int i = 1; i <= n; i++) 
//         fac[i] = (fac[i - 1] * i) % p; 
  
//     return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
#define mod 1000000007
ll fun(ll n,ll k){
  ll res;
  res=((n-k+1)%mod)*(k%mod);
   res=(res+1)%mod;
  return res;
}
 int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n,k;
  ll ans=0;
  cin>>n>>k;
  for(int i=k;i<=n+1;i++){
  	ans=(ans+fun(n,i))%mod;
  }
  cout<<ans;
}



  
