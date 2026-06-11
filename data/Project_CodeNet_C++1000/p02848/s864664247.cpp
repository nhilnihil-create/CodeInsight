

#include<stdio.h>
#include<string.h>
int main()
{
    int n,j,c;
    scanf("%d",&n);
    char s[10000];
    scanf("%s",&s);
    j=strlen(s);
    for(int i=0;i<j;i++){
        c = s[i] - 'A';
        s[i] = 'A' + (c+n)%26;

}
printf("%s",s);
return 0;
}