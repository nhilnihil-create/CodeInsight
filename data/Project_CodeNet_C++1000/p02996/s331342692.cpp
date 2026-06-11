#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,l;
    cin>>n;
    vl<pair<ll,ll>> job;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        job.pb({b,a});
    }
    sort(job.begin(),job.end());
    //for(i=0;i<n;i++) cout<<job[i].ff<<" "<<job[i].ss<<endl;
    ll tim=0;
    for(i=0;i<n;i++)
    {
        if(tim+job[i].ss<=job[i].ff) 
        {
            tim+=job[i].ss;
            //cout<<tim<<endl;
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}