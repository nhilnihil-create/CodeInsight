#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;

    int res = 0;
    while(n > 0)
    {
        n /= k;
        res++;
    }

    cout << res << "\n";
    return 0;
}