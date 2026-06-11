#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, t;
    cin >> n >> x >> t;
    printf("%d\n", (int)(ceil((float)n / (float)x) * t));
    return 0;
}