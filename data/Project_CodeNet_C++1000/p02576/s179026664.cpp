#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, t;
    cin >> n >> x >> t;

    cout << (n % x == 0 ? t * (n / x) : t * (n / x) + t) << "\n";
    return 0;
}