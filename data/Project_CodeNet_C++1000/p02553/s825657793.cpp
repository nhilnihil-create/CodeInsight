#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    lli a, b, c, d;
    cin >> a >> b >> c >> d;
    lli ac = a * c;
    lli ad = a * d;
    lli bc = b * c;
    lli bd = b * d;
    lli res = max(ac, max(bc, max(ad, bd)));
    cout << res << endl;
}