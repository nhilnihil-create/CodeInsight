#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int iquotient = a / b;
    int remainder = a % b;
    double fquotient = (double)a / b;

    printf("%d %d %.5f\n", iquotient, remainder, fquotient);
}