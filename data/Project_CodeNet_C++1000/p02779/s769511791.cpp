#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll i,j,n;
    vector<ll> s,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        ll q; cin>>q;
        s.push_back(q);
        t.push_back(q);
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    if(s.size()==t.size())
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}