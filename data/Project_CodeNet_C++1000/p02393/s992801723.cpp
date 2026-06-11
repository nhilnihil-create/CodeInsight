#include <stdio.h>

void swap(int num[], int a, int b)
{
    int tmp;
    tmp = num[a];
    num[a] = num[b];
    num[b] = tmp;
}

int main(void)
{
    int num[3];
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    int i, j;
    
    for(i = 0; i < 3; i++)
        for(j = i+1; j < 3; j++)
            if(num[i] > num[j])
            swap(num, i, j);
    printf("%d %d %d\n", num[0], num[1], num[2]);
    
    return 0;
    
}