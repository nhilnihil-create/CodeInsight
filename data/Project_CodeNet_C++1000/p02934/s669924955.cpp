#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <utility>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;
#define MX 1000000000

long long GCD(long long a, long long b)
{
    if (b > a)
        swap(a, b);
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}
long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, lcm = 1;
    cin >> N;
    vector<ll> vec(N);
    double cpp = 0;
    for (int i = 0; i < N; ++i)
    {
        long long tmp;
        cin >> tmp;
        cpp += double(1) / tmp;
    }

    // for (int i = 0; i < N; ++i)
    //     cin >> vec[i];
    // ll bunshi = 1;
    // ll bunbo = vec[0];
    // for (ll i = 1; i < N; ++i)
    // {
    //     bunshi = vec[i] * bunshi + bunbo;
    //     bunbo *= vec[i];
    //     if (bunbo % bunshi == 0)
    //     {
    //         bunshi = 1;
    //         bunbo /= bunshi;
    //     }
    // }
    cout << fixed << setprecision(15);
    cout << 1 / cpp << "\n";
}
