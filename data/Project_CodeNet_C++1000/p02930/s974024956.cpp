#include <iostream>
#include <cstring>

#define reset(a, b) memset(a, b, sizeof(a))

using namespace std;

const int maxn = 501;
int n;
int a[maxn], color[maxn][maxn];

void dq(int l, int r, int cnt)
{
    if (l == r)
        return;
    int m = (l + r)/2;
    for (int i = l; i <= m; i++)
        for (int j = m+1; j <= r; j++)
            color[a[i]][a[j]] = color[a[j]][a[i]] = cnt;
    dq(l, m, cnt+1);
    dq(m+1, r, cnt+1);
}

int main()
{
    cin >> n;
    reset(a, 0);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    reset(color, 0);
    dq(1, n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
            cout << color[i][j] << ' ';
        cout << '\n';
    }
}
