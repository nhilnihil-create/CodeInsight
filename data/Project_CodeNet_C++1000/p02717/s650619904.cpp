#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    swap(x, y);
    swap(x, z);
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    solve();
    return 0;
}