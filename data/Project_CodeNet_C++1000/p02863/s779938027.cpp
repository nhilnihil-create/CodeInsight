#include <cstdio>
#include <algorithm>
using namespace std;

int N, T;
int A[3000], B[3000];
int r[3000];
int knapsack[6000];

bool cmp(int i, int j) {
        return A[i] < A[j];
}

int main() {
        scanf("%d%d", &N, &T);
        for (int i = 0; i < N; i++) {
                scanf("%d%d", &A[i], &B[i]);
                r[i] = i;
        }
        sort(r, r + N, cmp);
        for (int i = 1; i <= T; i++)
                knapsack[i] = -1;
        for (int i = 0; i < N; i++)
                for (int j = T + A[r[i]] - 1; j >= A[r[i]]; j--)
                        if (knapsack[j - A[r[i]]] >= 0)
                                knapsack[j] = max(knapsack[j], knapsack[j - A[r[i]]] + B[r[i]]);
        int ans = 0;
        for (int i = 0; i < 6000; i++)
                ans = max(ans, knapsack[i]);
        printf("%d\n", ans);
        return 0;
}
