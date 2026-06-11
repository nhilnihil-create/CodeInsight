#include <stdio.h>
 
int main()
{
    int H1, M1, H2, M2, K;
    scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);
    int totalHours = (H2-H1)*60;
    int totalMinutes = M2-M1;
    printf("%d\n", totalHours+totalMinutes-K);
    return 0;
}