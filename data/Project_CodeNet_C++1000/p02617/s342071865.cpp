#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
} 

ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    ll res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    ll denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

ll f[200001];
 
ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a; 
 while(b > 0)
    {
        if(b%2 == 1)
    {
        x=(x*y);
        if(x>MOD) x%=MOD;
    }
    y = (y*y);
    if(y>MOD) y%=MOD; 
    b /= 2;
    }
 return x;
}
 
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
 return pow(n,MOD-2,MOD);
}
 
ll C(ll n, ll r, ll MOD)
{
 
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=nxtl();
    ll test=0;
    for(int i=1;i<=n;i++)
    {
        test+=(i)*(n+1-i);
    }
    for(int i=1;i<=n-1;i++)
    {
        ll u=nxtl(),v=nxtl();
        if(v<u)
        {
            ll temp=u;
            u=v;
            v=temp;
        }
        test-=(u*(n+1-v));
    }
    cout<<test<<endl;
    


    return 0;   
}


 
 
