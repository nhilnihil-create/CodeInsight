#include<stdio.h>
int main()
{
    int n,i,j,k,c=0;
    scanf("%d", &n);
    int s[n+5];
    for(i=0;i<n;i++)
    {
        scanf("%d", &s[i]);
    }
    for(i=1;i<n-1;i++)
    {
        if(s[i-1]<s[i])
        {
            if(s[i]<s[i+1])
                c++;
        }
        else if(s[i-1]>s[i])
        {
            if(s[i]>s[i+1])
                c++;
        }
    }
    printf("%d\n", c);
}
