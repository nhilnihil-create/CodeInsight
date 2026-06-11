#include<bits/stdc++.h>
using namespace std;

#define fastio std::ios::sync_with_stdio(false);
#define ll long long
#define scann(n) scanf("%d",&n)
#define scand(n) scanf("%lf",&n)
#define scans(s) scanf("%s",&s)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define full v.begin(),v.end()
#define debug cout<<"Bug! Vag! Bagh!"<<endl;
#define pi acos(-1)
#define mx 10010
#define inf 10e10

int main()
{
    ll n;
    cin>>n;
    set<ll>s;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        s.insert(x);
    }
    if(s.size()==n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
///arBishal_2017331022
