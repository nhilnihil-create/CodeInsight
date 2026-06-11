#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define mod 1000000007;
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    ll temp=a-b;
    if(a-b>=c)
    cout<<0;
    else
    cout<<c-(a-b);
    return 0;
}