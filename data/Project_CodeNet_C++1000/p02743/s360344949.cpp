#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    lli a, b, c;
    cin >> a >> b >> c;
    if (c - a - b > 0 && 2 * a * b - a * a - b * b < c * c - 2 * c * (a + b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}