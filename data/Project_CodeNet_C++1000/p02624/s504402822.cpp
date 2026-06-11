   #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ff first
    #define ss second
    #define pb push_back
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define MOD 1000000007
    #define pll pair<ll,ll>
constexpr ll INF = 1999999999999999997; 
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    #define MAXN 10000005
    int spf[MAXN];
    void seive()
    {
        for(int i=1;i<MAXN;i++)
            spf[i]=i;

        for(int i=2;i<MAXN;i+=2)
            spf[i]=2;

        for(int i=3;i*i<MAXN;i++)
        {  if(spf[i]==i)
            {
           for(int j=i*i;j<MAXN;j+=i)
           {
              if(spf[j]==j)
                spf[j]=i;
           }
          }
        }
    }  

    ll prod(ll x)
    {  ll res=1;
        map<ll,ll>m;
        while(x!=1)
        {
          m[spf[x]]++;
          x=x/spf[x];
        }
        for(auto j:m)
        {
            res=res*(j.ss+1); 
        }
        return res;
    }
 

    int main() {
        fastio;
        seive();
        ll n;
        cin>>n;
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            ans=ans+prod(i)*i;
        }
        cout<<ans<<endl;

    }