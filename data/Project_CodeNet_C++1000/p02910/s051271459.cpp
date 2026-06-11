#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
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
    string S;
    cin >> S;

    bool ok = true;
    for (ll i = 0; i < S.size(); i++)
    {
        if (i % 2 == 0) {
            ok &= S[i] == 'R' || S[i] == 'U' || S[i] == 'D';
        } else {
            ok &= S[i] == 'L' || S[i] == 'U' || S[i] == 'D';
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}