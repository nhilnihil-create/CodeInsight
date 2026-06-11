#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &L[i], &R[i]);
    sort(L, L + n);
    sort(R, R + n);
    if (n % 2)
        printf("%d\n", R[n / 2] - L[n / 2] + 1);
    else {
        int lef = (L[(n - 1) / 2] + L[n / 2]);
        int rig = (R[(n - 1) / 2] + R[n / 2]);
        printf("%d\n", rig - lef + 1);
    }
    return 0;
}
