#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll left = 4 * a * b;
    ll right = c - a - b;
    cout << (right > 0 && left < right * right ? "Yes" : "No") << endl;
    return 0;
}