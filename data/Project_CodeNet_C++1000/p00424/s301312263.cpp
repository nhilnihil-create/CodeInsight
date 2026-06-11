#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c[8];
    while(1){
        gets(c);
        int n=atoi(c);
        if( n<=0 ) break ;
        char s[255];
        for( int i=0;i<255;i++ ) s[i]=i;
        for( int i=0;i<n;i++ ){
            gets(c);
            s[c[0]]=c[2];
        }
        gets(c);
        n=atoi(c);
        for( int i=0;i<n;i++ ){
            gets(c);
            printf("%c",s[c[0]]);
        }
        printf("\n");
    }
    return 0 ;
}