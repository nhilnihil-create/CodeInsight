    #include<bits/stdc++.h>
    #define ll long long
    #define f   first
    #define s   second
    #define pb          push_back
    #define mod         1000000007
    #define hell        998244353
    #define inf         1000000000000000000LL
    using namespace std;
    ll n,k,m,l,mx,sum,q;

    void solve()
    {   ll a,b,x,y,c;
        string s;
        cin>>n>>k>>c;
        cin>>s;
        ll L[k],R[k];
        x=0;
        ll ini=0;
        while(x<k && ini<n)
        {
            if(s[ini]=='x') {ini++;continue;}
            {
                L[x]=ini+1;
                ini+=(c+1);
                x++;
            }
        }
        reverse(s.begin(),s.end());
        ini=0;
        x=0;
        while(x<k && ini<n)
        {
            if(s[ini]=='x') {ini++;continue;}
            {
                R[x]=n-ini;
                ini+=(c+1);
                x++;
            }
        }
        reverse(R,R+k);
        for(int i=0;i<k;i++)
        {   //cout<<L[i]<<" "<<R[i]<<"\n";
            if(L[i]==R[i]) cout<<L[i]<<"\n";
        }

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
