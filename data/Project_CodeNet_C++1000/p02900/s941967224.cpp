//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}

int main()
{
    ios;
    ll a,b;
    cin>>a>>b;
    ll g=__gcd(a,b);
    map<ll,ll>m;
    m[1]=1;
    for(ll i=2;i*i<=g;i++)
    {
        if(g%i==0)
        {
            m[i]=1;
            while(g%i==0)
                g/=i;
        }
    }
    m[g]=1;
    ll sum=0;
     map<ll,ll>::iterator it;
     for(it=m.begin();it!=m.end();it++)
        sum+=it->ss;
    cout<<sum<<endl;



}





