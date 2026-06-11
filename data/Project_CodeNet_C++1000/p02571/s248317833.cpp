#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
using namespace std;
using ll =long long;


int main()
{
    string a,b;
    cin>>a>>b;

    ll n=a.size();

    ll ans=1e14;
    fr(i,0,n-b.size()+1)
    {
        ll s=0;
        fr(j,0,b.size())
        {
            if(a[i+j]!=b[j])s++;
        }
        //cout<<a[i]<<endl;
        ans=min(ans,s);
    }

    cout<<ans<<endl;




}

























