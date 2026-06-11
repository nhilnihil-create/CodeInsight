    #include<bits/stdc++.h>
    #define ll long long
    #define f   first
    #define s   second
    #define pb          push_back
    #define mod         1000000007
    #define hell        998244353
    #define inf         1000000000000000000LL
    using namespace std;
    ll n,k,m,l,mx,sum,q,P;
    ll pref[2000005];
    void solve()
    {   ll a,b,x,y,c;
        cin>>n>>P;
        string s;
        cin>>s;
        ll ans=0;
        if(P==5 || P==2)
        {
            for(int i=1;i<=n;i++)
            {
                if((s[i-1]-'0')%P==0)
                    ans+=i;
            }
        }
        else
        {
            map<int,int> hm;
            hm[0]=1;
            ll p=1;
            ll rem=0;
            for(int i=n-1;i>=0;i--)
            {
                rem=((s[i]-'0')*p+rem)%P;
                hm[rem]++;
                p=(p*10)%P;
            }
            for(auto x:hm)
            {
                ll y=x.s;
                ans+=(y*(y-1))/2;
            }
        }
        cout<<ans;
        
           
    }    
    int main()
    {  
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        //cout<<primes.size();
        ll t=1;
        //cin>>t;
        while(t--)
            solve();

    }
