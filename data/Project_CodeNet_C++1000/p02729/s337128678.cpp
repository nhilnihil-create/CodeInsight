#include <stdio.h>

int main()
{
    int numA, numB, sumBall, sum, count = 0;
    scanf("%d %d", &numA, &numB);
    sumBall = numA + numB;
    int ball[sumBall];

    for(int i = 0; i < numA; i++)
    {
        ball[0] = 2;
        ball[i + 1] = ball[i] + 2;
    //    printf("%d\n", ball[i]);
    }

    for(int i = numA; i < sumBall; i++)
    {
        ball[numA] = 1;
        ball[i + 1] = ball[i] + 2;
    //    printf("%d\n", ball[i]);
    }

    for(int i = 0; i < sumBall; i++)
    {
        for(int j = i + 1; j < sumBall; j++)
        {
            sum = 0;
            //printf("%d + %d\n", ball[i], ball[j]);
            sum = ball[i] + ball[j]; 
            if (sum % 2 == 0) count++;
        }
    }
    printf("%d", count);
    return 0;
}