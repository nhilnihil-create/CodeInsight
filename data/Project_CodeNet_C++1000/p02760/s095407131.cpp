#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3][3]={},n;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(k==a[i][j])
                    a[i][j]=-1;
            }
        }
    }
    bool flag=false;
    for(int i=0; i<3; i++)
    {
        if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&a[i][0]==-1)
            flag=true;
        if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&a[0][i]==-1)
            flag=true;
    }
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==-1)
        flag=true;
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[1][1]==-1)
        flag=true;
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

