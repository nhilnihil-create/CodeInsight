#include <cstdio>

int main()
{
    int X;
    scanf("%d", &X);
    for (int A = 0; A < 120; ++A)
    {
        for (int B = 0; B < A; ++B)
        {
            int a5 = A * A * A * A * A;
            int b5 = B * B * B * B * B;
            if (a5 - b5 == X)
            {
                printf("%d %d", A, B);
                return 0;
            }
            else if (a5 + b5 == X)
            {
                printf("%d %d", A, -B);
                return 0;
            }
        }
    }
}
