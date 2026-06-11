#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[15][100006];
int t = 0;
int s=0;
int sum = 1e9;
int n, m, x;
int tt = 0;
int b[15];
bool solve()
{
    for (int i = 1; i <= m;i++)
        if(b[i]<x)
            return false;
    return true;
}
void dfs(int k)
{

    if(k==n)
    {
        if(solve())
            sum = min(s, sum);
        return;
    }
    for (int j = 1; j <= m; j++)
        b[j] += a[k][j];
    s += a[k][0];
    dfs( k + 1);
    for (int j = 1; j <= n; j++)
        b[j] -= a[k][j];
    s -= a[k][0];
    dfs(k + 1);
}
int main()
{

    memset(b, 0, sizeof(b));
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    dfs( 0);
    if(sum==1e9)
        cout << "-1" << endl;
    else
        cout << sum << endl;
    system("pause");
}