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
    ll a, b, c;
    cin >> a >> b >> c;
    if (c - a - b < 0)
        cout << "No\n";
    else if (4 * a * b < (c - a - b) * (c - a - b))
        cout << "Yes\n";
    else
        cout << "No\n";
}
