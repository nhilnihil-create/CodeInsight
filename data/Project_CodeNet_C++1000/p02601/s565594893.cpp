#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (b <= a && k--) b *= 2;
    while (c <= b && k--) c *= 2;
    if (k >= 0 && (c > b && b > a)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}