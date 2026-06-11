#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //your code starts here
    ll n;
    cin >> n;
    ll sum = 0LL;
    for (ll k = 1; k <= n; k++)
    {
        ll lim = n / k;
        sum += (k * lim * (lim + 1)) / 2;
    }
    cout << sum;
    return 0;
}
