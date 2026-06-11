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
 
ll mod=1e9+7;  
vector <vector <int>  > g;
int n,k; 

void dfs(int s,vector <bool> &visited,int k,ll &test);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f[0] = 1;
    for(ll i = 1 ; i <= 200000 ; i++)
        f[i] = (f[i-1]*i)%mod;

    n=nxt();k=nxt();
    vector <int> row;
    g.resize(n+1,row);

    for(int i=0;i<n-1;i++)
    {
        int u=nxt(),v=nxt();
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <bool> visited;
    visited.resize(n+1,0);
    ll test=1;
    if(k<g[1].size()+1)
    {
        cout<<"0\n";
        return 0;
    }
    (test*=k)%=mod;
    (test*=C(k-1,g[1].size(),mod))%=mod;
    (test*=f[g[1].size()])%=mod;
    //cout<<test<<endl;
    dfs(1,visited,k-2,test);
    cout<<test<<endl;

    
    
    
    return 0;   
}

void dfs(int s,vector <bool> &visited,int k,ll &test)
{
    visited[s]=1;
    if(s!=1)
    {
        if(k<g[s].size()-1){
            test=0;
            return;
        }
        if(g[s].size()>1){
            test=(test*C(k,g[s].size()-1,mod))%mod;
            test=(test*f[g[s].size()-1])%mod;
            for(auto i:g[s])
                if(!visited[i])
                    dfs(i,visited,k,test);
        }
        //cout<<s<<" "<<test<<endl;
    }
    else
    {
        for(auto i:g[s])
            dfs(i,visited,k,test);
    }
}


 
 
