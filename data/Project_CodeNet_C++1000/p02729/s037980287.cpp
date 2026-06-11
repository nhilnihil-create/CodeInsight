#include<stdio.h>
int main() {
    int N, M, total;
    scanf("%d %d", &N, &M);
    N = ((N-1)*N/2);
    M = ((M-1)*M/2);
    total = N + M;
    printf("%d\n", total);
    return 0;
}
