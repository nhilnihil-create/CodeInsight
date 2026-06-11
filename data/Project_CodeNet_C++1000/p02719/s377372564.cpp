#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, x, y;
    cin >> n >> k;
    x = min(k - (n % k), n % k);
    cout << x << endl;
}