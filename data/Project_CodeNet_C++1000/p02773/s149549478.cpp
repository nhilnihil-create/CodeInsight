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

bool cmp(pair<string,ll>x,pair<string,ll>y)
{
    if(x.second==y.second) return x.first<y.first;
    else return x.second>y.second;
}

int main()
{
    ll n;
    cin>>n;
    map<string,ll>m;
    string s;
    ll x;
    for(ll i=0;i<n;i++)
    {
        cin>>s;
        m[s]++;
    }

    vector< pair<string,ll> >v;

    copy(m.begin(),m.end(),back_inserter(v));

    sort(full,cmp);

    ll flag=0;

    for(ll i=0;i<v.size();i++)
    {
        if(v[i].second>v[i+1].second)
        {
            cout<<v[i].first<<endl;
            break;
        }
        else
        {
            cout<<v[i].first<<endl;
        }
    }

    return 0;
}
///arBishal_2017331022
