#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int k, a, b;
    cin >> k >> a >> b;
    a = (a + k - 1) / k;
    a *= k;
    if (a <= b)
        cout << "OK";
    else
        cout << "NG";
}