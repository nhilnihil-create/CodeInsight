#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    ll K, X;
    cin >> K >> X;

    for (ll i = max(X - K + 1, -100000LL); i <= min(X + K - 1, 100000LL); i++)
    {
        cout << i << (i == min(X + K - 1, 100000LL) ? "\n" : " ");
    }
    
}