#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int r;
    scanf("%d", &r);
    --n;
    int maxv=-2000000000, minv=r, x;
    while(n--)
    {
        scanf("%d", &x);
        maxv=max(maxv, x-minv);
        minv=min(minv, x);
    }
    printf("%d\n", maxv);
    return 0;
}

