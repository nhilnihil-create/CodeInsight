#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
 
using namespace std;
 
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
 
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    ll test=0;
    int i=n-1;
    int prev=n+3;
    //cout<<n<<endl;
    while(i>=0)
    {
        if((s[i]-48>4&&i-1>=0&&s[i-1]-48>4)||s[i]-48>5)
        {int x=i;
            while(i>=0&&s[i]-48>4)
            {
                test+=(9-(s[i]-48));
                i--;
            }
            if(prev==x+2&&prev<n&&s[x+1]-48==4)
                test+=1;
            else
                test+=2;
        prev=i+1;
        }
        else
        {
            if(s[i]-48==5&&i+2==prev&&i+2<n&&s[i+1]-48==4)
                prev=i;
            test+=(s[i]-48);
            i--;
        }
    }
    cout<<test<<endl;

    return 0;   
}
 
 