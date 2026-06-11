#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n ,k ;
    cin >> n >> k;
    vector<ll> Right;
//    Right.push_back(0);
    string s;
    cin >> s;
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(s[i-1]=='R')
        {
            Right.push_back(i);
        }
        
        
    }
    for(ll i=0;i<n;i++)
    {
        if(s[i]==s[i+1] && i+1<n && s[i]=='R')
        {
            ans++;
        }
        if(s[i]==s[i-1]&& s[i]=='L' && i-1>=0)
        {
            ans++;
            
        }
    }
    vector<ll> diff;
    cout << min(ans+2*k,n-1);
}
