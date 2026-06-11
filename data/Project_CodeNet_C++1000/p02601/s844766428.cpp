#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (b <= a)
        b <<= 1, k--;
    while (c <= b)
        c <<= 1, k--;
    if (k < 0)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}
