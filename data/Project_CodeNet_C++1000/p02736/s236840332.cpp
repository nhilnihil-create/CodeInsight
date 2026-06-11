#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 10;

int N, A[MAX_N];

int main() {
    scanf("%d", &N);
    static char S[MAX_N]; scanf("%s", S + 1);
    for (int i = 1; i <= N; i++) A[i] = S[i] - '1';
    bool any_1 = false;
    for (int i = 1; i <= N; i++) if (A[i] == 1) any_1 = true;
    if (any_1)
        for (int i = 1; i <= N; i++) A[i] &= 1;
    else
        for (int i = 1; i <= N; i++) A[i] /= 2;
    int ans = 0;
    N--;
    for (int i = 0; i <= N; i++)
        if ((i & N) == i) ans ^= A[i + 1];
    printf("%d\n", ans * (any_1 ? 1 : 2));
}
