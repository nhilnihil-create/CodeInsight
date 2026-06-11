#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

int main()
{
    int n;
    cin>>n;

    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.pb(k);
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            auto itr=lower_bound(v.begin(),v.end(),v[i]+v[j]);
            ll ng=distance(itr,v.end());
            ans+=(n-1-i)-ng;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
