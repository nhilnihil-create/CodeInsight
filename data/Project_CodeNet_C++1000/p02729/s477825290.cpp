#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << n * (n - 1) / 2 + m * (m - 1) / 2 << endl;
}