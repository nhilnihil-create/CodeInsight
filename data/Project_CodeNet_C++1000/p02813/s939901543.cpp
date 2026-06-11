#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;


int main()
{
    ll t,i,j,k,ans,n,x;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        vector<ll> a(n),b(n);

        rep(p,0,n)cin>>a[p];
        rep(p,0,n)cin>>b[p];

        i=0;
        while(a[i]==b[i] && i<n)i++;

        if(i==n)cout<<"0";
        else 
        {
            if(a[i]>b[i])swap(a,b);

            ans=0;
            while(a!=b)
            {
                bool flag = next_permutation(all(a));
                ans++;
            }
            cout<<ans;
        }
    }
    return 0;
}

