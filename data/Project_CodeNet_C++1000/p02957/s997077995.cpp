#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;
    ll k = abs(a-b);
    if(k%2)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << min(a, b) + k/2 << endl;
    }
    return 0;
}
