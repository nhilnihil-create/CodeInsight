#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,g;
    vector<vector<int>> brojevi(3,vector<int>(3));
    vector<vector<bool>> p(3,vector<bool>(3,false));
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            cin >> brojevi[i][j];
    cin >> n;
    for (int k=0;k<n;k++)
    {
        cin >> g;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if(brojevi[i][j]==g)
                    p[i][j]=true;
    }
    if(p[0][0] && p[1][0] && p[2][0] || p[0][1] && p[1][1] && p[2][1] || p[0][2] && p[1][2] && p[2][2] ||
       p[0][0] && p[0][1] && p[0][2] || p[1][0] && p[1][1] && p[1][2] || p[2][0] && p[2][1] && p[2][2] ||
       p[0][0] && p[1][1] && p[2][2] || p[0][2] && p[1][1] && p[2][0])
        cout << "Yes";
    else
        cout << "No";
}
