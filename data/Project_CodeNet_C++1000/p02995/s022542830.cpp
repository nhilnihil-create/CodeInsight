#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

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
    a--;
    ll r = b/c + b/d - b/lcm(c,d);
    ll l = a/c + a/d - a/lcm(c,d);
    ll baisu = r - l;

    ll ans = b - a  - baisu;
    cout << ans << endl;
    return 0;
}