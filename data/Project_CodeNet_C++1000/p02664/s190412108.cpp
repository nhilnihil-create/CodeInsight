#include<cstdio>
#include<cstring>
char s[200005];

int main(){
    scanf("%s",s+1);
    int n = strlen(s+1);
    for(int i = 1; i <= n; i++){ 
        if(s[i]=='?') printf("D");
        else printf("%c",s[i]);
    }
    printf("\n");    
    return 0;
}
