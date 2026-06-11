    #include<bits/stdc++.h>
    typedef long long ll;
    const ll mod=998244353;
    using namespace std;
    int boom[100005];
    int a[100005];
    ll ksm(ll a,ll b)
    {
        ll ans=1;
        for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
        return ans;
    }
    int main()
    {
        int n;cin>>n;
        int mx=0;
        ll sum=1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            boom[a[i]]++;
            mx=max(mx,a[i]);
        }
        if(a[0]!=0||boom[0]!=1) cout<<0<<endl;
        else
        {
            for(int i=1;i<=mx-1;i++)
            {
                sum=sum*ksm(boom[i],boom[i+1])%mod;
            }
            cout<<sum<<endl;
        }
        
        return 0;
    }
