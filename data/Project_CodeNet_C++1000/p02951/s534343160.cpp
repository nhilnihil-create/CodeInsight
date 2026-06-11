
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
const long long INF = 1LL << 60;
ll mod = 1e9 + 7;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c - (a - b) >= 0)
        cout << c - (a - b) << endl;
    else
    {
        cout << 0 << endl;
    }

    return 0;
}