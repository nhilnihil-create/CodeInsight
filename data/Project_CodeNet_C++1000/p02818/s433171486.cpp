#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    cout << max(a - k, (ll)0) << " " << max(b - max(k - a, (ll)0), (ll)0) << endl;
    return 0;
}