#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[505];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0, ii = i;
        while(ii % 2 == 0)
        {
            ii /= 2;
            cnt++;
        }
        a[i] = cnt + 1;
    }
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d ", a[j]);
        }
        puts("");
    }
    return 0;
}
