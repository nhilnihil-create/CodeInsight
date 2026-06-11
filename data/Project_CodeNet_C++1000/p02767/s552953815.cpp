#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,c,d,a,l,r;
    cin>>n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    ll ans=INT_MAX,cnt;
    for(i=v[0]; i<=v[n-1]; i++)
    {
        cnt=0;
        for(j=0; j<n; j++)
        {
            x=abs(i-v[j]);
            x=x*x;
            cnt+=x;
        }
        ans=min(cnt,ans);
    }
    cout<<ans<<'\n';
}












