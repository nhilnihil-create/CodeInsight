#include <stdio.h>

int main()
{
    int N,R,hasil;

    scanf("%d %d", &N, &R);
    if (N<10){
        hasil += R + 100 * (10 - N);
    }
    else{
        hasil= R;
    }
    printf("%d",hasil);

    return 0;
}