#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b)
{
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

ll lcm(ll a, ll b)
{
   return (ll)a * b / gcd(a, b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}