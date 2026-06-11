#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if(N % 10 == 7){
        printf("Yes\n");
    } else if (((N - (N % 10)) / 10) % 10 == 7) {
        printf("Yes\n");
    } else if ((N - (N % 10) - ((((N - (N % 10)) / 10) % 10) * 10)) / 100 == 7) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}