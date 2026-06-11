#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main()
{
    ll a, b ;
    cin >> a >> b ;

    cout << lcm(a,b) << endl ;
}