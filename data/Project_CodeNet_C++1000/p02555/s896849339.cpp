#pragma GCC optimize "trapv"
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,n) for(int i=a;i<n;i++)
#define all(v) v.begin(),v.end()
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
unsigned long long power(unsigned long long x, 
                         int y, int p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCrModPFermat(unsigned long long n, 
                                 int r, int p) 
{ 
    // Base case 
    if (r == 0) 
        return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
int main()
{
    fio;
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll s;
        cin>>s;
        ll n=s/3;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            sum=((sum%mod)+(nCrModPFermat(s-i*3+i-1,i-1,(int)1e9+7)))%mod;
        }
        cout<<sum<<endl;
    }
}