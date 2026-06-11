#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    cout << t2 - k - t1 << endl;
    return 0;
}