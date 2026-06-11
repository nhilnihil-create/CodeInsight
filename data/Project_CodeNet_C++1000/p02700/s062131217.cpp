#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int i = 0;
    while(a > 0 && c > 0)
    {
        if(i++ % 2 == 0) c -= b;
        else a -= d;
    }

    cout << (c <= 0 ? "Yes" : "No") << "\n";
    return 0;
}