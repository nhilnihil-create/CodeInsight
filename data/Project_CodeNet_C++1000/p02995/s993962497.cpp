#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll n=b-a+1;
    ll cn,dn;
    if(a%c==0) cn=b/c-a/c+1;
    else cn=b/c-a/c;
    if(a%d==0) dn=b/d-a/d+1;
    else dn=b/d-a/d;
    ll m=lcm(c,d),mn;
    if(a%m==0) mn=b/m-a/m+1;
    else mn=b/m-a/m;

    ll ans=n-cn-dn+mn;
    cout << ans << endl;

}