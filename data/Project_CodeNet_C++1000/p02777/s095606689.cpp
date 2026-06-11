#include <stdio.h>
#include <string.h>

int main()
{
    char S[255], T[255];
    scanf("%s%s", S, T);
    int A,B;
    scanf("%d%d", &A, &B);
    char U[20];
    scanf("%s", U);

    int result1 = strcmp(S,U);
    int result2 = strcmp(T,U);

    if (result1 == 0)
    {
        A = A - 1;
    }
    if (result2 == 0)
    {
        B = B - 1;
    }
    printf("%d%s%d", A," ", B);
    return 0;
}