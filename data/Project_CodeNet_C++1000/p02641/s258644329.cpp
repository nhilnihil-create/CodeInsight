#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
map<ll,ll>cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,n,t,a,b,c,l,r,q;
    cin>>k>>n;
    for(i=1; i<=n; i++)
    {
        cin>>r;
        cnt[r]++;
    }
    vector<pair<ll,ll>>v;
    x=k;
    while(1)
    {
        if(cnt[x]==0)
        {
            v.pb(x,x-k);
            break;
        }
        x++;
    }
    y=k;//cout<<cnt[5];
    while(1)
    {
        if(cnt[y]==0)
        {
            v.pb(y,k-y);
            break;
        }
        y--;
    }
  //  cout<<y<<'\n';
    if(v[0].second==v[1].second)
        cout<<v[1].first<<'\n';
    else if(v[0].second<v[1].second)
        cout<<v[0].first<<'\n';
    else
        cout<<v[1].first<<'\n';
}




