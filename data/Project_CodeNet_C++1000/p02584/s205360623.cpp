#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    ll y=min(k,x/d);
    k=k-y;
    x=x-y*d;
    if(k%2==0)
        cout<<x;
    else
        cout<<d-x;
}