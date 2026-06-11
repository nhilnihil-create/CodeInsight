#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, a, b, res, rem;
    cin >> n >> a >> b;

    res = (n / (a + b)) * a;
    rem = n % (a + b);
    
    if(rem < a)
        res += rem;
    else res += a;

    cout << res << "\n";

    return 0;
}