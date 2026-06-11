#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long p1 = a*c, p2 = a*d, p3 = b*c, p4 = b*d;

    cout << max(p4, max(p3, max(p1, p2))) <<  endl;
    return 0;
}
