#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
const int N = 5007;
int n, m, a, b;
int ans[N][N];
int main()
{
    cin >> n >> m >> a >> b;

    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            ans[i][j] = 0 + ((i <= b && j <= a) || (i > b && j > a));
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j <= m; ++ j)
        printf("%d", ans[i][j]);
        puts("");
    }
    return 0;
}
