#include <stdio.h>
#include<string.h>

int main() {
    int k;
    char s[105];
    scanf("%d\n %s", &k, s);
    int len = strlen(s);
    
    if (strlen(s)>k) {
        s[k]='.';
        s[k+1]='.';
        s[k+2]='.';
        s[k+3]='\0';
    }
	printf("%s", s);
    return 0;
}
