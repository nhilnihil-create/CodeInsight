

#include<bits/stdc++.h>
using namespace std;
#define ll long  long int 

int main()
{   
    ll n;
    cin>>n;
    vector<ll>v;
    map<ll, ll>f;
    for(long int i=0;i<n;i++)
    {
           ll x;
           cin>>x;
           v.push_back(x);
           if(f.count(x))
           {
               f[x]+=1;
           }
           else{
               f.insert(make_pair(x, 1));
           }
    }
    map<ll , ll>m;
    ll all=0;
    for(auto x:f)
    {
        ll y=x.second;
        ll val=y*(y-1)/2;
        m.insert(make_pair(x.first, val));
        all+=val;
    }
      
        ll tall=all;
       for(ll i=0;i<n;i++)
       {
              all-=m[v[i]];
              ll val=f[v[i]];
              val--;
              all+=val*(val-1)/2;
              cout<<all<<endl;
             all=tall;
       }
    return 0;
}