#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fats ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()
{
    fats;
    ll a,b,c,k;cin>>a>>b>>c>>k;
    while(b<=a && k>0)
    {
        b=b*2;
        k--;
    }
    while(c<=b && k>0)
    {
        c=c*2;
        k--;
    }
    if(c>b && b>a)cout<<"Yes";
    else cout<<"No";
    // cout<<c<<b<<a;
}