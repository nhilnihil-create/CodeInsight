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
#include <utility>
#include <queue>
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

ll fact(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1) % MOD;
}

int main()
{
    ll N, K, S;
    cin >> N >> K >> S;

    ll s = S;
    ll mode = 0;
    ll cnt = 0;

    vector<ll> ans;
    for (ll i = 0; i < N; i++)
    {
        if (i < K) {
            cout << S;
        } else {
            if (S == 1000000000) {
                cout << 1;
            } else {
                cout << 1000000000;
            }
        }
        if (i == N - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i == ans.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}