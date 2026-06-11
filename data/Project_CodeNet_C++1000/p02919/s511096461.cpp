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
    vector <int> v(n+1);
    vector <pair<ll,ll> > left,right;
    left.resize(n+1,{0,0});
    right.resize(n+1,{n+1,n+1});
    for(int i=1;i<=n;i++)
        cin>>v[i];

    stack <int> s1,s2,temp;
    for(int i=n;i>=1;i--)
    {
        while(s1.size()&&v[s1.top()]<v[i])
        {
            left[s1.top()].first=i;
            int x=s1.top();
            s1.pop();
            temp.push(x);
        }
        while(s2.size()&&v[s2.top()]<v[i])
        {
            left[s2.top()].second=i;
            s2.pop();
        }
        s1.push(i);
        while(temp.size())
        {
            int x=temp.top();
            temp.pop();
            s2.push(x);
        }

    }

    while(s1.size())
        s1.pop();
    while(s2.size())
        s2.pop();
    while(temp.size())
        temp.pop();
    for(int i=1;i<=n;i++)
    {
        while(s1.size()&&v[s1.top()]<v[i])
        {
            right[s1.top()].first=i;
            int x=s1.top();
            s1.pop();
            temp.push(x);
        }
        while(s2.size()&&v[s2.top()]<v[i])
        {
            right[s2.top()].second=i;
            s2.pop();
        }
        s1.push(i);
        while(temp.size())
        {
            int x=temp.top();
            temp.pop();
            s2.push(x);
        }

    }

    ll test=0;
    for(int i=1;i<=n;i++)
    {
        ll count=0;
        if(left[i].first!=0)
        {
            count+=((left[i].first-left[i].second)*(right[i].first-i));
        }
        if(right[i].first!=0)
        {
            count+=((i-left[i].first)*(right[i].second-right[i].first));
        }
        test+=(count*v[i]);
    }    

    cout<<test<<endl;
    
    return 0;   
}


 
 
