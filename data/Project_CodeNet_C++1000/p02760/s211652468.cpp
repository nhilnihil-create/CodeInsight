#include <bits/stdc++.h>
using namespace std;

int a[3][3];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for(int i=0;i<9;i++)cin>>a[i/3][i%3];

    int n=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        for(int j=0;j<9;j++) if(b==a[j/3][j%3])a[j/3][j%3]=0;
    }

    for(int i=0;i<3;i++)
    {
        if(a[i][0]+a[i][1]+a[i][2]==0)
        {
            cout<<"Yes\n";
            return 0;
        }
        if(a[0][i]+a[1][i]+a[2][i]==0)
        {
            cout<<"Yes\n";
            return 0;
        }
    }
    if(a[0][0]+a[1][1]+a[2][2]==0)
    {
        cout<<"Yes\n";
        return 0;
    }
    if(a[0][2]+a[1][1]+a[2][0]==0)
    {
        cout<<"Yes\n";
        return 0;
    }

    cout<<"No\n";

    return 0;
}
