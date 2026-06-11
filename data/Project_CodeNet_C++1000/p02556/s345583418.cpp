/*         
               JAI SHREE RAM    */
 
 
 
#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define int             long long
#define mp              make_pair
#define pr              pair<long long,long long>
#define vr              vector<long long>
#define mod            1000000007
#define mod2            998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define ll              long long
#define ld	            long double
#define w(x)            int x; cin>>x; while(x--)
#define fill(a,b)       memset(a, b, sizeof(a))
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 

const int N = 1000001;
  vector <int> a;
int power(int x, unsigned int y) 
{ 
    int res = 1;     
   
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = res*x; 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
 
long long maxSubArray(long long a[], int sze)
{
   long long max_so_far = 0, max_ending = 0;
   for (int i = 0; i < sze; i++)
   {
       max_ending = max_ending + a[i];
       if (max_ending < 0)
           max_ending = 0;
       else if (max_so_far < max_ending)
           max_so_far = max_ending;
   }
   return max_so_far;
}
 
 
 
ll factorialNumInverse[N + 1]; 
ll naturalNumInverse[N + 1]; 
ll fact[N + 1]; 
  
 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
ll Binomial(ll N, ll R, ll p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 

 
void solve()
{
    int n;
    cin>>n;
    
    int ma1=-1e18,ma2=-1e18,mi1=1e18,mi2=1e18;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        
        if(x+y>=ma1)ma1=x+y;
         if(x+y<mi1)mi1=x+y;
        
        if(x-y>ma2)ma2=x-y;
        if(x-y<mi2)mi2=x-y;
    }
    int ans=max(ma1-mi1,ma2-mi2);
    
    cout<<ans<<"\n";
}
 
int32_t main()
{ 
      
      ios;
      int test;
     
      
      test=1;
   //  cin>>test;
    
      while(test--)
      {
          solve();
      }
       
    
    return 0;
	}