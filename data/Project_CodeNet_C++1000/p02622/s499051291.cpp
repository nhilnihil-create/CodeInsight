#include <cstdio>
#include <cstring>

#define mx 200005
char S[mx],T[mx];

int main(){
    scanf("%s",S);
    scanf("%s",T);

    int ans=0;
    for(int i=0;i<strlen(S);i++)
        ans+=(S[i]!=T[i]);
    printf("%d\n",ans);
}
