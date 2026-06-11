#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a,b;
    cin>>a>>b;
    ll ans=(a*b)/2;
    if((a*b)%2) ans++;
    if(min(a,b)==1)
    {
        cout<<"1";
        return 0;
    }
    cout<<ans;
}