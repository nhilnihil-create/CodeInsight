#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#define MAX 0x3f3f3f3f
using namespace std;

int mpa[12][12];

int n,flag;

void floyd()
{
    for(int k=0; k<=10; k++)
    {
        for(int i=0; i<=10; i++)
        {
            for(int j=0; j<=10; j++)
            {
                if(mpa[i][j]>mpa[i][k]+mpa[k][j])
                    mpa[i][j]=mpa[i][k]+mpa[k][j];
            }
        }
    }
}


int main()
{
    while(cin>>n,n!=0)
    {
        flag=0;
        memset(mpa,MAX,sizeof(mpa));
        for(int i = 1; i <= n; i++)
        {
            int a, b, c;
            cin>>a>>b>>c;

            if(mpa[a][b]>c)
            {
                mpa[a][b]=c;
                mpa[b][a]=c;
            }
        }

        floyd();

        for(int i=0; i<=10; i++)
            mpa[i][11]=0;

        int  mmin=MAX,a1,a2,flag=0;
        for(int i=0; i<=10; i++)
        {
            for(int j=0 ; j<=10; j++)
            {
                if(i == j)
                    mpa[i][j]=0;
                if(mpa[i][j]!=MAX)
                    mpa[i][11]+=mpa[i][j];
            }
            if(mmin>mpa[i][11] && mpa[i][11]!=0)
            {
                mmin=mpa[i][11];
                a1=i;
            }
        }

        cout<<a1<<" "<<mpa[a1][11]<<endl;

    }
    return 0;
}