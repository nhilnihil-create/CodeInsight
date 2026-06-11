#include<bits/stdc++.h>
#define ll long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
int main()
{
    FAST();
    ll i,j,k,n,l,x,y,v,w,T;
   // vector<ll>v;
    map<ll,ll>m;
    string s;
    cin>>x>>v>>y>>w>>T;
    double f,g,h,t;
    ll a=abs(x-y);
    f=(w*a*1.0)/((v-w)*1.0);
    t=f/(w*1.0);
    h=T*1.0;
    if(t<=h&&t>0)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
