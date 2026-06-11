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

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    if (H == 1 || W == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    ll a, b;
    a = (W + 1) / 2;
    b = W / 2;
    ll all;
    ll c, d;
    c = (H + 1) / 2;
    d = H / 2;
    ll result = a * c + b * d;
    cout << result << "\n";
}
