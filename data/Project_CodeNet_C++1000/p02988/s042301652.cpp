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
    ll N;
    cin >> N;
    vector<ll> perm(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> perm[i];
    }
    
    ll ans = 0;
    for (ll i = 0; i < N - 2; i++)
    {
        if (perm[i] > perm[i + 1] && perm[i + 1] > perm[i + 2]
         || perm[i] < perm[i + 1] && perm[i + 1] < perm[i + 2]) {
            ans++;
        }
    }
    cout << ans << endl;
}