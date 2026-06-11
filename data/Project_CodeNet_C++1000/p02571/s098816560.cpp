#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int l1,l2,i,j,ans,m;
    char s1[1002],s2[1002];

    scanf("%s%s",s1,s2);
    l2=strlen(s2);
    l1=strlen(s1);
    l1=l1-l2+1;
    for(i=0,ans=0;i<l1;i++)
    {
        for(j=0,m=0;j<l2;j++)
        {
            if(s1[i+j]==s2[j])
                m++;
        }
        ans=max(ans,m);
    }
    printf("%d\n",l2-ans);
    return 0;
}
