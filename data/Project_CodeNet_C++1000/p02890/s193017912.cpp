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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt();
    vector <int> v(n);
    generate(all(v),nxt);
    sort(v.begin(),v.end());
    vector <int> v2;
    int i=0;
    while(i<n)
    {
        int x=i;
        while(i<n&&v[x]==v[i])
            i++;
        v2.push_back(i-x);
    }
    sort(v2.begin(),v2.end());
    int m=v2.size();
    vector <int> prefix(m);
    prefix[0]=v2[0];
    for(int i=1;i<m;i++)
        prefix[i]=prefix[i-1]+v2[i];
    vector <int> v3(n+1);
    for(int k=1;k<=n;k++)
    {//cout<<"came\n";
        int l=0,r=m-1;
        int test=m;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v2[mid]>=k)
            {
                test=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        v3[k]=m-test;
        if(test-1>=0)
            v3[k]+=(prefix[test-1]/k);
    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        int l=1,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v3[mid]>=i)
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    
    return 0;   
}


 
 
