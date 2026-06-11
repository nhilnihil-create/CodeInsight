#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int N, S, ans;

void rec(int base, int x, int used) {
    if(x == S && used == N) {
        ans += 1;
        return;
    }
    if(x > S) return;
    for(int i = base; i <= 9; i++) {
        rec(i + 1, x + i, used + 1);
    }
}

int main(void) {
    while(1) {
        scanf("%d%d", &N, &S);
        if(N == 0 && S == 0) break;
        ans = 0;
        rec(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}