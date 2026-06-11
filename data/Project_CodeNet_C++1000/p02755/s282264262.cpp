#include <cstdio>
#include <cmath>

int main()
{
    int a, b; std::scanf("%d %d", &a, &b);
    int n = -1;

    for (int i=0; i<=b*15; i++)
    {
        if (a == (int)(i*0.08) && b == (int)(i*0.1))
        {
            n = i;
            break;
        }
    }

    printf("%d\n", n);

    return 0;
}