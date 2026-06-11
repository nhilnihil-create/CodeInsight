#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
const int Maxn = 52;
int n;
int X[Maxn], Y[Maxn];
map <ii, int> M;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int dx = X[i] - X[j], dy = Y[i] - Y[j];
            if (dx || dy) M[ii(dx, dy)]++;
        }
    int mx = 0;
    for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++)
        mx = max(mx, it->second);
    printf("%d\n", n - mx);
    return 0;
}