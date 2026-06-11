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
    vector <queue<int> >  v;
    queue <int> row;
    v.resize(n+1,row);
    vector <map<int,int> >  v2;
    map <int,int> r2;
    v2.resize(n+1,r2);
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            x=nxt();
            v[i].push(x);
            v2[i][x]=j;
        }
    }
    int days=0;
    bool f=1;
    //vector <bool> visited,visited2;
    //visited.resize(n+1,0);
    //visited2.resize(n+1,0);

    //map <int,set <int> > next;
    set <pair<int,int> > s2;
    for(int i=1;i<=n;i++)
    {
        if(v[v[i].front()].front()==i){
            if(i<v[i].front())
                s2.insert({i,v[i].front()});
            else
                s2.insert({v[i].front(),i});
        }
            
    }
    //vector <int> remove_count;
    //remove_count.resize(n+1,0);
    
    
    while(s2.size()>0)
    {set <pair<int,int> > s3;
        days++;
        for(auto it=s2.begin();it!=s2.end();it++)
        {
            v[it->first].pop();
            v[it->second].pop();
        }
        for(auto it=s2.begin();it!=s2.end();it++)
        {
            int i=it->first;
            if(v[i].size()&&v[v[i].front()].size()&&v[v[i].front()].front()==i){
            if(i<v[i].front())
                s3.insert({i,v[i].front()});
            else
                s3.insert({v[i].front(),i});
            }

            i=it->second;
            if(v[i].size()&&v[v[i].front()].size()&&v[v[i].front()].front()==i){
            if(i<v[i].front())
                s3.insert({i,v[i].front()});
            else
                s3.insert({v[i].front(),i});
            }
        }
        s2.clear();
        s2=s3;

    }

    for(int i=1;i<=n;i++)
        if(v[i].size())
        {
            f=0;
            break;
        }
    if(!f)
        cout<<"-1\n";
    else
        cout<<days<<endl;
    
    
    
    return 0;   
}


 
 
