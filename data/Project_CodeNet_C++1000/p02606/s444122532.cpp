#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, d, cnt = 0;
    scanf("%d%d%d", &l, &r, &d);
    for (int i = l; i <= r; i++)
    {
        if (!(i % d))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}