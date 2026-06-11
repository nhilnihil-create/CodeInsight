#include <stdio.h>
int main()
{
    int n, m;
    //n = odd
    //m = even
    scanf("%d %d", &n, &m);
    int even = n * (n - 1) / 2;
    int odd = m * (m - 1) / 2;
    int total = odd + even;
    printf("%d\n", total);
    return 0;
}