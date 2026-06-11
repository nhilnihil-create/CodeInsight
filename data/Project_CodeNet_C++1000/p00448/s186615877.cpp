#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;

bitset<10000> cake[10];

int main()
{
    int r, c;
    int result, ans, tmp;
    while(~scanf("%d%d", &r, &c))
    {
       if(r==0 &&c==0) break;
       for(int i=0; i<r; i++)
         for(int j=0; j<c; j++)
         {
            bool upwards;
            scanf("%d", &upwards);
            cake[i][j]=upwards;
         }
       int cnt=1<<r;
       result=0;
       for(int i=0; i<cnt; i++)
       {
           for(int j=0; j<r; j++)
           {
               if(i&(1<<j))
                cake[j].flip();
           }
           ans=0;
           for(int j=0; j<c; j++)
           {
               tmp=0;
               for(int k=0; k<r; k++)
               {
                   if(cake[k][j])
                    tmp++;
               }
               ans+=max(tmp, r-tmp);
           }
           for(int j=0; j<r; j++)
           {
               if(i&(1<<j))
                cake[j].flip();
           }
           if(result<ans) result=ans;
       }
       printf("%d\n", result);
    }

    return 0;
}