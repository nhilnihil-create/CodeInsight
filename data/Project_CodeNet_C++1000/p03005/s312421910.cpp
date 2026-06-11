#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
        cout << 0 << endl;
    else
        cout << n - k << endl;
    return 0;
}
