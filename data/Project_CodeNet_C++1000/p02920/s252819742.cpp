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

    map <int,int, greater<int>> m1;
    int n=nxt();
    int k=power(2,n,1e8);
    for(int i=0;i<k;i++)
    {
        int x=nxt();
        m1[x]+=1;
    }
    //cout<<"came 2\n";
    multiset <int> s;
    s.insert(m1.begin()->first);
    m1.begin()->second-=1;
    if(m1.begin()->second==0)
        m1.erase(m1.begin());
    bool f=1;
    for(int i=1;i<=n;i++)
    {vector <int> v;
        //cout<<"came\n";
        for(auto it=s.begin();it!=s.end();it++)
        {
            int x=*it;
            auto it2=m1.upper_bound(x);
            if(it2==m1.end())
            {//cout<<x<<endl;
                f=0;
                break;
            }
            //cout<<x<<" "<<it2->first<<endl;
            it2->second-=1;
            v.push_back(it2->first);
            if(it2->second==0)
                m1.erase(it2);
        }
        //cout<<"new set: ";
        //for(auto it=s.begin();it!=s.end();it++)
           // cout<<*it<<" ";
        //cout<<endl;
    for(int j=0;j<v.size();j++)
        s.insert(v[j]);

        if(!f)
            break;
    }

    if(!f)
        cout<<"No\n";
    else
        cout<<"Yes\n";

    
    
    return 0;   
}


 
 
