#include <bits/stdc++.h>
#include<list>
#include<algorithm>
#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define rep(a,b,c) for(a=b;a<c;a++)
#define repj(a,b,c) for(a=b;a<c;a++)
#define repr for(i=n-1;i>=0;i--)
#define pii pair<ll,ll>
#define pll pair<ll, ll>
#define inf 100000001
const double pie  =3.141592653589793238463;
#define mod 1000000007
#define lb lower_bound
#define up upper_bound
#define rep1 for(i=1;i<=n;i++)
#define vr vector
#define POP(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define ef else if
#define all(x) (x).begin(), (x).end()
#define SORT(A) sort(A.begin(),A.end());
#define REV(A) reverse(A.begin(), A.end());
#define lenth length()
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n" 
const ll dx[4] = { -1, 1, 0, 0};
const ll dy[4] = {0, 0, -1, 1};
ll XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
ll YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
#define precise(x) cout<<fixed<<setprecision(x)
#define t1(x)                cerr<<#x<<": "<<x<<endl
#define t2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define t4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define t5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define t6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
using namespace std;
void SieveOfEratosthenes(ll n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // for (ll p=2; p<=n; p++) 
       // if (prime[p]) 
          // cout << p << " "; 
} 
ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  
  
int main()
{
   fastio
   ll t,i,j,k,l,m,n,a,x,b,y,z,c,h,d,f,e,p,o,nl,np,q,r,g;
   cin>>n;
   ll brr[105];
   ll sum=0;
   ll arr[106];
   rep(i,0,n-1)
   {
    cin>>brr[i];
   }
   arr[0]=brr[0];
   arr[n-1]=brr[n-2];
   rep(i,1,n-1)
   {
       arr[i]=min(brr[i-1],brr[i]);
   }

   rep(i,0,n)
   sum+=arr[i];


   cout<<sum<<endl;

}