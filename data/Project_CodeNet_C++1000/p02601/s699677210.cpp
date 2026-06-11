#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e6 + 34;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (a >= b) b *= 2, k--;
    while (b >= c) c *= 2, k--;
    if (k >= 0) cout << "Yes";
    else cout << "No";
}
