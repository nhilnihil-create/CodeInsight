#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, S;
    scanf("%d%d%d", &N, &K, &S);
    for (int i = 1; i <= K; i ++) {
        printf("%d ", S);
    }
    S += S == 1000000000 ? -1 : 1;
    for (int i = K + 1; i <= N; i ++) {
        printf("%d ", S);
    }
    printf("\n");
    return 0;
}