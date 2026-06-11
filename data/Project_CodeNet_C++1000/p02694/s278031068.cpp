#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, i = 100;
    cin >> x;

    int res = 0;
    while(i < x)
    {
        i += i/100;
        res++;
    }

    cout << res << "\n";
}