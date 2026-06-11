#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r, d;
    cin >> l >> r >> d;
    int s = (l + d - 1) / d * d;
    int e = r / d * d;
    cout << 1 + (e - s) / d;

    return 0;
}
