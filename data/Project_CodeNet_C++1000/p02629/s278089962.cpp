#include <stdio.h>
#include <string.h>
 
int main()
{
    long long m;
    scanf("%lld",&m);
    char s[100]={0};
    int i=0;
    m--;
    while(m>=0){
        s[i]=m%26+'a';
        m/=26;
        i++;
        m--;
    }
    for(int j=i-1;j>=0;j--){
        printf("%c",s[j]);
    }
    return 0;
}