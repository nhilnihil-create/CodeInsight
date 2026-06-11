#include <bits/stdc++.h>
#define maxN 502

using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i, printf("\n"))
    {
        for (int j = i + 1; j <= n; ++ j)
        {
            int val = i ^ j;
            for (int k = 0; ; ++ k)
                if (val & (1 << k))
            {
                printf("%d ", k + 1);
                break;
            }
        }
    }
    return 0;
}
