//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    bool bl = 0;
    int a, b;
    int n, c = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &a, &b);
        if (a == b)
            ++c;
        else
            c = 0;
        bl |= (c >= 3);
    }
    if (bl)
        puts("Yes");
    else
        puts("No");
}