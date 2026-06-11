#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll k, x;
    cin >> k >> x;
    for (ll i = x - k + 1; i <= x + k - 1; i++)
        cout << i << " ";
    cout << endl;
    return 0;
}