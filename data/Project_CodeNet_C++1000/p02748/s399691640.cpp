#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int A, B, M;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d %d %d", &A, &B, &M);
    int mna = Maxn, mnb = Maxn;
    for (int i = 0; i < A; i++) {
        scanf("%d", &a[i]);
        mna = min(mna, a[i]);
    }
    for (int i = 0; i < B; i++) {
        scanf("%d", &b[i]);
        mnb = min(mnb, b[i]);
    }
    int res = mna + mnb;
    for (int i = 0; i < M; i++) {
        int x, y, c; scanf("%d %d %d", &x, &y, &c); x--; y--;
        res = min(res, a[x] + b[y] - c);
    }
    printf("%d\n", res);
    return 0;
}
