#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
int main()
{
    ///"In the name of Allah,most gracious and most merciful"///

    ll i,j,x,y,z,count=100000000000,sum=0,n,ans=0;
    cin>>n;
    ll a[n];
    rep(i,n)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    for(j=a[n-1]; j>=a[0]; j--)
    {

        ll mid=j;
        rep(i,n)
        {
            ans=ans+((a[i]-mid)*(a[i]-mid));
        }

        count=min(count,ans);
        ans=0;

    }

    cout<<count<<endl;

    return 0;
}




