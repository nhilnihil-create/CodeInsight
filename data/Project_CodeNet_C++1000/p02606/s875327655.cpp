#include<stdio.h>
int main()
{
    int l, r, d;
    int h = 0;
    scanf("%d %d %d", &l, &r, &d);
    for( int i = l; i <= r; i++)
    {
        if (i % d == 0)
        {
            h++;
        }
    }
    printf("%d", h);
    return 0;
}