#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, q, r, sum = 0;
    cin >> p >> q >> r;

    sum = max(max(p, q), r);
    if(p == sum)
        cout << q + r << endl;
    else if(r == sum)
        cout << p + q << endl;
    else cout << r + p << endl;

    return 0;
}