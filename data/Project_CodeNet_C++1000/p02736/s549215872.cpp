// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 19;
int n, F[N];
char A[N];
int main()
{
    scanf("%d%s", &n, &A);
    for (int i = 0; i < n; i ++)
        A[i] -= '1';
    for (int i = 1; i <= n; i ++)
        F[i] = F[i - 1] + __builtin_ctz(i);
    int Pr = 0;
    for (int i = 0; i < n; i ++)
        if (A[i] == 1 && F[n - 1] - F[i] - F[n - 1 - i] == 0)
            Pr ^= 1;
    if (Pr) return !printf("1\n");
    for (int i = 0; i < n; i ++)
        if (A[i] == 1)
            return !printf("0\n");
    for (int i = 0; i < n; i ++)
        A[i] /= 2;
    Pr = 0;
    for (int i = 0; i < n; i ++)
        if (A[i] == 1 && F[n - 1] - F[i] - F[n - 1 - i] == 0)
            Pr ^= 1;
    if (Pr) return !printf("2\n");
    return !printf("0\n");
}