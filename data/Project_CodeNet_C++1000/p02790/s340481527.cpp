#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)

int main(void)
{
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    if (a > b)
        rep(i, 0, a) ans = 10 * ans + b;
    else
        rep(i, 0, b) ans = 10 * ans + a;
    cout << ans << endl;
}
