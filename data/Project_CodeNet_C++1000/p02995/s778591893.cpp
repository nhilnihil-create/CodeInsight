#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,d;
    ll l=0,r=0;
    cin>>a>>b>>c>>d;
    l=b/c-(a-1)/c;
    r=b/d-(a-1)/d;
    ll g=__gcd(c,d);
    g=(c*d)/g;
    ll x=b/g-(a-1)/g;
    cout<<(b-a+1)+x-(r+l)<<endl;
    return 0;
}