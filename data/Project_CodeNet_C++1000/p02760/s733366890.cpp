#include<bits/stdc++.h>
using namespace std;
int n, i, temp, A[3][3], j, k;
bool cond, vis[3][3];
int main()
{
    memset(vis, false, sizeof(vis));
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin >> A[i][j];
        }
    }
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> temp;
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                if(A[j][k]==temp)
                    vis[j][k] = true;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        if(vis[i][0] && vis[i][1] && vis[i][2]) cond = true;
        if(vis[0][i] && vis[1][i] && vis[2][i]) cond = true;
    }
    if(vis[1][1] && vis[2][2] && vis[0][0]) cond = true;
    if(vis[0][2] && vis[1][1] && vis[2][0]) cond = true;
    if(cond)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
