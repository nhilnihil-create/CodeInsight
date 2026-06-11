#include <stdio.h>
#include <string.h>

int main()
{
    char ballA[15], ballB[15], input[15];
    int numBallA, numBallB;

    scanf("%s %s", ballA, ballB);
    scanf("%d %d%*c", &numBallA, &numBallB);
    scanf("%s", input);

    if (strcmp(input, ballA) == 0)
    {
        numBallA--;
    } else if (strcmp(input, ballB) == 0)
    {
        numBallB--;
    }

    printf("%d %d", numBallA, numBallB );

    return 0;
}