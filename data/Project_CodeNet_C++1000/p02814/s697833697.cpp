#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;

ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}

int main()
{
    ll t,i,j,k,ans,n,m;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n>>m;

        ll lc = 1;
        vector<ll> v(n);
        rep(p,0,n){cin>>v[p];lc = lcm(lc,v[p]);}

        ll val = ((v[0] ^ (v[0]-1))+1)/2;
        bool flag=true;

        rep(p,1,n)
        {
            if(val != ((v[p] ^ (v[p]-1))+1)/2){flag=false;break;}
        }
        if(flag)
        {
            lc/=2;
            ans = (m/lc) - (m/(2*lc));
            cout<<ans;
        }else cout<<"0";
    }
    return 0;
}

