#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll tmp = min(a, k);
    a -= tmp;
    k -= tmp;
    b -= min(k, b);
    cout << a << " " << b << endl;
    return 0;
}