#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    if ((b - a) % 2 == 0)
        cout << (b - a) / 2 << endl;
    else
        cout << min(a - 1, n - b) + 1 + (b - a - 1) / 2 << endl;
}