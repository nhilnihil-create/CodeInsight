#include <stdio.h>
#include <string.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int memo[100000]; for(int i=0;i<m;i++) memo[i]=0;
    int ac=0,wa=0;
    for(int i=0;i<m;i++)
    {
        int p;
        char s[3];
        scanf("%d%s",&p,s);
        if(memo[p]!=-1)
        if(strcmp(s,"WA")==0)
        {
            memo[p]++;
        }
        else
        {
            wa+=memo[p];
            memo[p]=-1;
            ac++;
        }
    }
    printf("%d %d\n",ac,wa);
}