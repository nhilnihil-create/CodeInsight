#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e2+5;
int n, m, f[N][N]; char a[N][N];
int main()
{
    scanf("%d%d", &n, &m); for(int i = 1; i <= n; ++i) scanf("%s", a[i]+1);
    memset(f, 0x3f, sizeof(f)), f[1][1] = a[1][1] == '#';
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
    {
        if(i != n) f[i+1][j] = min(f[i+1][j], f[i][j]+(a[i][j] != '#'&&a[i+1][j] == '#'));
        if(j != m) f[i][j+1] = min(f[i][j+1], f[i][j]+(a[i][j] != '#'&&a[i][j+1] == '#'));
    }
    printf("%d\n", f[n][m]);
    return 0;
}