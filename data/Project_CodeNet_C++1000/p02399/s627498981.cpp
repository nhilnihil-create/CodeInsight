#include <cstdio>

int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d %f", a/b, a%b, 1.0*a/b);
    return 0;
}