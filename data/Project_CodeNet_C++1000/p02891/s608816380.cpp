#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102, INF = 1000000009;

int n;
char a[N];
int k;

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf(" %s", a);
    n = strlen(a);
    scanf("%d", &k);
    bool z = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != a[0])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        printf("%lld\n", (n * 1LL * k) / 2);
        return 0;
    }
    int yans = 0;
    int q = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            yans += (q / 2);
            q = 1;
        }
        else
            ++q;
    }
    yans += (q / 2);
    if (a[0] != a[n - 1])
    {
        printf("%lld\n", (yans * 1LL * k));
    }
    else
    {
        int q1 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != a[0])
            {
                q1 += i;
                break;
            }
        }
        int q2 = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != a[0])
            {
                q2 += (n - i - 1);
                break;
            }
        }
        if (q1 % 2 == 1 && q2 % 2 == 1)
            printf("%lld\n", (yans * 1LL * k) + (k - 1));
        else
            printf("%lld\n", (yans * 1LL * k));
    }
    return 0;
}
