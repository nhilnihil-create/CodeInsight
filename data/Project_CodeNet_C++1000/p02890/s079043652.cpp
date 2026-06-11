#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[300005];
int b[300005];
int c[300005];
int d[300005];
int e[300005];
int f[300005];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[a[i]]++;
        c[b[a[i]]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = d[i - 1];
        d[i] += c[i];
        e[d[i] / i]++;
    }
    for(int i = n; i >= 1; i--)
    {
        f[i] = f[i + 1];
        f[i] += e[i];
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", f[i]);
    }
    return 0;
}
