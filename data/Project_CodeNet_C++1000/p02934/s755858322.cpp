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
    dd N;
    cin >> N;

    dd sum = 1;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        dd ai;
        cin >> ai;
        sum *= ai;
        A[i] = ai;
    }

    dd son = sum;
    dd mother = 0;
    for (ll i = 0; i < N; i++)
    {
        mother += (dd)sum / A[i];
    }
    cout << fixed << setprecision(10) << (dd)(son) / (dd)(mother) << endl;
}