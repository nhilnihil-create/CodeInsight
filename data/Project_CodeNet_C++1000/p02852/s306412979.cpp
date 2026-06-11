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
    int n=nxt(),m=nxt();
    
    string s;
    cin>>s;
    if(m>=n)
    {
        cout<<n<<endl;
        return 0;
    }
    vector <int> dp;
    vector <int> dp2;
    dp.resize(n+1,-1);
    dp2.resize(n+1);
    map <int, set<int> > m2;
    dp[0]=0;
    set <int> s2;
    m2[0]=s2;
    m2[0].insert(0);
    for(int i=1;i<=n;i++)
    {//cout<<i<<" "<<m2.size()<<endl;
        if(i-m-1>=0&&dp[i-m-1]!=-1)
        {//cout<<"delete\n";
            m2[dp[i-m-1]].erase(i-m-1);
            if(m2[dp[i-m-1]].size()==0)
                m2.erase(dp[i-m-1]);
        }
        if(s[i]=='0'&&m2.size()>0)
        {//cout<<"came here: "<<i<<endl;
            auto it=m2.begin();
            dp[i]=it->first+1;
            dp2[i]=*((it->second).begin());
            if(m2.find(dp[i])==m2.end())
                m2[dp[i]]=s2;
            m2[dp[i]].insert(i);

        }
        //cout<<i<<" "<<dp[i]<<" "<<dp2[i]<<endl;

    }

    if(dp[n]==-1)
    {
        cout<<"-1\n";
    }
    else
    {
        vector <int> v;
        int cur=n;
        while(cur!=0)
        {
            v.push_back(cur);
            cur=dp2[cur];
        }
        v.push_back(0);
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
            cout<<v[i+1]-v[i]<<" ";
        cout<<endl;
    }



    
    
    

    return 0;   
}


 
 
