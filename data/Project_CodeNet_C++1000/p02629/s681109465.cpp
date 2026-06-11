#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll n;vector<char>v;
    cin>>n;
    while(n!=0)
    {
        ll x=n%26;
        if(x==0)
        {
            x=x+26;
        }
        char c=(char)(96+x);
        v.push_back(c);
        if(n%26==0)
            n=n/26 -1;
        else
            n=n/26;
    }
    for(ll i=v.size()-1;i>=0;i--)
        cout<<v[i];
}

    
