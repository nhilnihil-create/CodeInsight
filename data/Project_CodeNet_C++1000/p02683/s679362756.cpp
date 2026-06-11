#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ANS = 1e10, sum;
struct node
{
    int c, a[20];
} p[20];
int ans[15], v[20];
int n, m, x,ii;
void dfs(int cnt, int pre)
{
    if (cnt == ii)
    {
        sum = 0;
        fill(v, v + 20, 0);  //记录总的学习程度
        for (int j = 0; j < cnt; j++)
        {
            for (int k = 0; k < m; k++)
                v[k] += p[ans[j]].a[k];
            sum += p[ans[j]].c;
        }
        int flag = 1;
        for (int j = 0; j < m; j++)
            if (v[j] < x)
            {
                flag = 0;
                break;
            }
        if (flag)
            ANS = min(ANS, sum);
        return;
    }
    for (int j = 0; j <= n; j++)
    {
        if (j > pre)
        {
            pre = j;
            ans[cnt] = pre;
            dfs(cnt + 1, pre);
        }
    }
}
int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].c;
        for (int j = 0; j < m; j++)
            cin >> p[i].a[j];
    }
    for (ii = 1; ii <= n; ii++)
    {
        dfs(0, 0);
    }
    if (ANS == 1e10)
        puts("-1");
    else
        cout << ANS;
    return 0;
}
