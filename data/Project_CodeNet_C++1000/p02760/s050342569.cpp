#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=5;
int a[N][N];
bool win()
{

    if(a[0][0]==-1 && a[1][1]==-1 && a[2][2]==-1)
        return 1;

    if(a[0][2]==-1 && a[1][1]==-1 && a[2][0]==-1)
        return 1;

    if(a[0][0]==-1 && a[0][1]==-1 && a[0][2]==-1)
        return 1;
    if(a[1][0]==-1 && a[1][1]==-1 && a[1][2]==-1)
        return 1;
    if(a[2][0]==-1 && a[2][1]==-1 && a[2][2]==-1)
        return 1;

    if(a[0][0]==-1 && a[1][0]==-1 && a[2][0]==-1)
        return 1;

    if(a[0][1]==-1 && a[1][1]==-1 && a[2][1]==-1)
        return 1;
    if(a[0][2]==-1 && a[1][2]==-1 && a[2][2]==-1)
        return 1;


return 0;


}
void change(int x)
{

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(a[i][j]==x)
            {
                a[i][j]=-1;
            }
        }

}
int main()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            cin>>a[i][j];
        }
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        change(x);
    }
    if(win()){
        printf("Yes");
    }
    else{
        printf("No");
    }

}
