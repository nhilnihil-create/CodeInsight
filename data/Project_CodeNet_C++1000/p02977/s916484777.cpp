#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    if (__builtin_popcount(N) == 1) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    
    if (N%2 == 1) {
        for (int i = 2; i <= N; i+=2) {
            printf("1 %d\n", i);
            printf("1 %d\n", i+1);
            printf("%d %d\n", i, N+i+1);
            printf("%d %d\n", i+1, N+i);
        }
        printf("%d %d\n", N+1, N+2);
    }else {
        for (int i = 2; i <= N-2; i+=2) {
            printf("1 %d\n", i);
            printf("1 %d\n", i+1);
            printf("%d %d\n", i, N+i+1);
            printf("%d %d\n", i+1, N+i);
        }
        printf("%d %d\n", N+1, N+2);
        int d = 1;
        while ((N&d) == 0) d <<= 1;
        printf("%d %d\n", N, d+1);
        printf("%d %d\n", N*2, N^d);
        
    }
    return 0;
}
