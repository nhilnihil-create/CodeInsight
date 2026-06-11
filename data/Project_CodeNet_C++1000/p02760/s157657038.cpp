#include <stdio.h>

int a[3][3];
int n;
int b[10];

int main()
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    scanf("%d",&a[i][j]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&b[i]);

    bool memo[3][3]={};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
        if(a[j][k]==b[i])memo[j][k]=true;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(memo[i][j]==false)
            {
                break;
            }
            if(j==2)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(memo[j][i]==false)
            {
                break;
            }
            if(j==2)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        if(memo[i][i]==false)
        {
            break;
        }
        if(i==2)
        {
            printf("Yes\n");
            return 0;
        }
    }
    for(int i=0;i<3;i++)
    {
        if(memo[i][2-i]==false)
        {
            break;
        }
        if(i==2)
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}