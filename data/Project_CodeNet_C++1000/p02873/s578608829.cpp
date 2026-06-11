#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




int main()
{
    string s;
    cin>>s;
    ll n = s.length();
    ll* a = new ll [n+1]();
    ll* b = new ll [n+1]();

    for(ll i=1;i<=n;i++)
    {
        if( s[i-1] =='<')
            a[i] = a[i-1] +1;
    }
    for(ll i = n-1;i>=0;i--)
    {
        if( s[i] =='>')
            b[i] = 1 +b[i+1];
    }
    ll ans =0;
    for(ll i=0;i<=n;i++)
    {
        ans += max( a[i] , b[i] );
    }
    cout<<ans;
}
