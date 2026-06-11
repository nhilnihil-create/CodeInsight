#include<bits/stdc++.h>
using namespace  std;


bool row( int a[][3]  )
{
    if( a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0 )
        return true;
    if( a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0 )
        return true;
    if( a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0 )
        return true;
    return false;
}
bool col( int a[][3])
{
    if( a[0][0]==0 && a[1][0]==0 && a[2][0]==0 )
        return true;
    if( a[0][1]==0 && a[1][1]==0 && a[2][1]==0 )
        return true;
    if( a[0][2]==0 && a[1][2]==0 && a[2][2]==0 )
        return true;
    return false;
}
bool diag( int a[][3])
{
    if( a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)
        return true;
    if( a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0)
        return true;
    return false;
}
int main()
{
    int a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        bool found = false;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if( a[i][j] == temp)
                {
                    a[i][j] =0;
                    found = true;
                    break;
                }
            }
            if( found ) break;
        }
    }

    bool ans = row(a) || col(a) || diag(a);
    if( ans )
        cout<<"Yes";
    else cout<<"No";

}