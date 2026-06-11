#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return(b);
    }
    else
    {
        return(gcd(b, a % b));
    }
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ansc = 0, ansd = 0, anscd = 0,ans = 0;
    if (a % c == 0)ansc++;
    ansc += b / c - a / c;
    
    if (a % d == 0)ansd++;
    ansd += b / d - a / d;

    if (a % d == 0 && a % c == 0)anscd++;
    ll tmp = lcm(c, d);
    anscd += b / tmp - a / tmp;;

    ans = (b - a + 1) - (ansc + ansd - anscd);
    cout << ans << endl;

    return 0;
}