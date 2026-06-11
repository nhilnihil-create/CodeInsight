#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if (t * (v - w) >= abs(a - b))
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}