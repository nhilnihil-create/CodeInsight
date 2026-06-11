#include<stdio.h>

int main()
{
    int n, cpy=0;
    char s[101];
    scanf("%d%s",&n,&s);
    for(int i=0,j=n/2;i<n;i++,j++){
        if(s[i]==s[j]){
            cpy++;
        }
    }
    n%2==0&&cpy==n/2?puts("Yes"):puts("No");
    return 0;
}