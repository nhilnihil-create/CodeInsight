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

double dist(ll x,ll y)
{
    double ans=sqrt(pow(x,2)+pow(y,2));
    //cout<<ans<<endl;
    return ans;
}

double max2(double x,double y)
{
    if(x>y)
        return x;
    return y;
}

#define PI 3.14159265

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt();
    vector <pair<ll,ll> > v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;    

    vector <pair<double,pair<ll,ll> > >v2(n);
  
    for(int i=0;i<n;i++)
    {
        double x=v[i].first;
        double y=v[i].second;
        double angle;
        if(x>=0&&y>=0)
        {
            if(x==0)
                angle=90;    
            else{
                angle=atan(y/x);
                angle*=(180/PI);
            }

        }
        else if(x>=0&&y<0)
        {
            if(x==0)
                angle=270;    
            else{
                angle=atan(-y/x);
                angle*=(180/PI);
                angle=360-angle;
            }
        }
        else if(x<0&&y>=0)
        {
            angle=atan(-y/x);
                angle*=(180/PI);
                angle=180-angle;
        }
        else
        {
            angle=atan(y/x);
                angle*=(180/PI);
                angle=180+angle;
        }
        v2[i]={angle,{v[i].first,v[i].second}};
        
    }
    sort(all(v2));
    for(int i=0;i<n;i++)
        v2.push_back(v2[i]);


    vector <pair<ll,ll> > prefix(2*n);
    prefix[0]=v2[0].second;
    for(int i=1;i<2*n;i++)
    {
        prefix[i].first=prefix[i-1].first+v2[i].second.first;
        prefix[i].second=prefix[i-1].second+v2[i].second.second;
    }

    //for(int i=0;i<n;i++)
        //cout<<i<<" "<<v2[i].first<<" "<<v2[i].second.first<<" "<<v2[i].second.second<<" "<<prefix[i].first<<" "<<prefix[i].second<<endl;
    double test=0;
    for(int i=1;i<n;i++)
        for(int j=i;j<n+i;j++)
        {
            test=max2(test,dist(prefix[j].first-prefix[i-1].first,prefix[j].second-prefix[i-1].second));
        }

    for(int i=0;i<1;i++)
        for(int j=i;j<n;j++)
        {
            test=max2(test,dist(prefix[j].first,prefix[j].second));
        }

    
    cout<<setprecision(15)<<test<<endl;

    
    return 0;   
}


 
 
