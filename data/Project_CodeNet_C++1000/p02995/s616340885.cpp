#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll a,b,c,d,p,q;
    cin>>a>>b>>c>>d;
    p=(a-1)/c+(a-1)/d-(a-1)/(c*d/__gcd(c,d));
    q=(b)/c+(b)/d-(b)/(c*d/__gcd(c,d));
    cout<<b-a+1-q+p;
}