#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
 bitset<10500> a[50];
int sum;
int r,c;

void dfs(int ans)
{
    if(ans==r)
    {
        int result=0;
        for(int j=0;j<c;j++)
        {
            int number=0;
            for(int i=0;i<r;i++)
            {
                if(a[i][j]) number++;
            }
            number=max(number,r-number);
            result+=number;
        }
        sum=max(sum,result);
        return ;
    }
    dfs(ans+1);
    a[ans].flip();
    dfs(ans+1);
    a[ans].flip();
}

int main(void)
{
   // freopen("C.txt","r",stdin);
  //  int r,c;
    while(scanf("%d%d",&r,&c)!=EOF&&(r||c))
    {

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                   bool temp;
                scanf("%d",&temp);
                a[i][j]=temp;
            }
        }
        sum=0;
        dfs(0);
        printf("%d\n",sum);


    }

    return 0;
}