#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define setbits(x)          __builtin_popcountll(x)
#define lp(a,n) for(ll i=a; i<n; i++)
#define lpi(a,n) for(int i=a; i<n; i++)
#define w(t) int t; cin>>t; while(t--)
#define vi vector<int> 
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define inf 1e9
#define LB lower_bound
#define UB upper_bound
const int mod = 1000000007;
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    return gcd(b%a,a);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

int prime[10000007];
void SieveOfEratosthenes(ll n) 
{ 
    memset(prime, -1, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
         
        if (prime[p] == -1) 
        { 
            for (ll i=p*p; i*i<=n; i += p) 
                prime[i] = p; 
        } 
    } 
    
} 
int lps(string s){
    int len = 0;
    int n = s.length();
    int dp[n];
    dp[0] = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[len]){
            len++;
            dp[i] = len;
            continue;
        }
        if(len!=0){
            len = dp[len-1];
            i--;
            continue;
        }
        dp[i]=0;
    }
    return dp[n-1];
}
 
ll power(unsigned ll x,unsigned  ll y) 
{ 
    ll res = 1;     
    while (y > 0) 
    { 
        if (y & 1) 
            res = res*x; 
   
        y = y>>1;
        x = x*x;  
    } 
    return res; 
}

vector<pair<ll, ll>> v;

void factorize(long long n) 
{ 
    int count = 0; 
  
    // count the number of times 2 divides  
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++; 
    } 
  
    // if 2 divides it 
    if (count) 
        v.pb({2,count}); 
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            v.pb({i,count});
    } 
  
    // if n at the end is a prime number. 
    if (n > 2) 
        v.pb({n,1}); 
} 


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    //SieveOfEratosthenes(1e12);
    ll n;
    cin>>n;
    v.clear();
    factorize(n);
    ll ans=0;
    lp(0,v.size()){
        ll c=v[i].ss;
        ll sans=0;
        for(int i=1; i<=c; i++){
            if((i*(i+1))/2 <= c){
                sans=i;
            }
            else break;
        }
        ans += sans;
    }
    cout<<ans<<endl;
}