///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define        u64             uint64_t
#define        ll              long long
#define        endl            "\n"
#define        PI              acos(-1)
#define        fi              first
#define        si              second
#define        mkp             make_pair
#define        pb              push_back
#define        set0(arr)       memset(arr, 0, sizeof(arr))
#define        setinf(arr)     memset(arr, 126, sizeof(arr))
#define        all(x)          (x).begin(),(x).end()
#define        sz(v)           ((int)(v).size())
#define        maxm         1000005
#define        IOS             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
using          pll        =      pair<ll, ll> ;
using          vl         =      vector<ll> ;
using          vpll       =      vector<pll> ;
using          mll        =      map<ll, ll> ;
using          mcl        =      map<char, ll> ;
using          msl        =      map<string,ll> ;
using          sl         =      set<ll> ;
using          sc         =      set<char> ;
using          dl         =      deque<ll> ;
const int N = 1e6+5 ;

ll      mod = 1e9+7 ;
vl      adj[N] ;
vpll    adjc[N] ;
ll      vis[N] ;
ll      arr[N],arr1[N] ;

bitset <maxm>isprime;
vector<long long >primes;
void autop()
{
    isprime.set();
    isprime[0]=isprime[1]=false;
    for(int i=0;i<maxm;i++)
    {
        if(isprime[i])
        {
            primes.push_back(i);
            for(int j=i*2;j<maxm;j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    IOS;
    ll a, b, c, d, n, m, p, x, y, z, i, j, k, f = 0, tc, cnt = 0, sum = 0, mul = 1, mi = 1e18, ma = -1e18;
    string   str ;
    char     ch ;
    double   db ;
    ll       l, r ;
    //code
        autop();
        cin>>n;
        for(i=0;i<n;i++) cin>>arr[i];
        mll mp;
        f=0;
        for(k=0;k<n;k++)
        {
               x=arr[k];
             ll num=x;
        for(i=0;primes[i]*primes[i]<=x&&num>1;i++)
        {
           if(num%primes[i]==0){
                     if(mp[primes[i]]==1) f=1;
                     mp[primes[i]]=1;
            while(num%primes[i]==0)
            {
                num=num/primes[i];
            }
           }
        }
        if(num!=1){
             if(mp[num]==1) f=1;
             mp[num]=1;
            }

        }



        if(f==0)
        {
               cout<<"pairwise coprime\n";
               return 0;
        }
         x=__gcd(arr[0],arr[1]);
        for(i=2;i<n;i++)
               x=__gcd(x,arr[i]);
        if(x==1)
               cout<<"setwise coprime\n";
        else
               cout<<"not coprime\n";


    //code
    return 0;
}


