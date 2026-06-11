#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int A[110];
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }

    // 承認するかどうか
    int isApproval = 1;

    for (int i = 0; i < N; ++i)
    {
        // 偶数かどうか
        if (A[i] % 2 == 0)
        {
            // 3 または 5 で割り切れるか => どちらでも割り切れないなら承認しない
            if (A[i] % 3 != 0 && A[i] % 5 != 0)
            {
                isApproval = 0;
            }
        }
    }

    if (isApproval)
    {
        printf("APPROVED\n");
    }
    else
    {
        printf("DENIED\n");
    }

    return 0;
}
