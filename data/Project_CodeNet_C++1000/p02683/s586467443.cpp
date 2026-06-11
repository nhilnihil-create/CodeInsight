#include <iostream>
using namespace std;
struct ST
{
  int c;
  int v[15];
};
ST b[15];
int a[15];
int n, m, x;
int f = 0;
bool judge()
{
    for(int i = 0; i < m; i++)
        if(a[i] < x)
            return false;
    return true;
}
void dfs(int sum, int up, int t)
{
    if(f == 1)
        return;
    if(sum > up)
        return;
    if(judge())
    {
        f = 1;
        return;
    }
    if(t >= n)
        return;
    dfs(sum, up, t + 1);
    if(sum + b[t].c > up)
        return;
    for(int i = 0; i < m; i++)
        a[i] += b[t].v[i];
    dfs(sum + b[t].c, up, t + 1);
    for(int i = 0; i < m; i++)
        a[i] -= b[t].v[i];
}
int main()
{

    cin >> n >> m >>x;
    int L = 0, R = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> b[i].c;
        R += b[i].c;
        for(int j = 0; j < m; j++)
            cin >> b[i].v[j];
    }
    int mid = 0;
    int ans = -1;
    while(L <= R)
    {
        mid = L + (R - L) / 2;
        f = 0;
        dfs(0, mid, 0);
        if(f == 1)
        {
            ans = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
