#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define mx 1003
char S[mx],T[mx];

int main(){
    scanf("%s",S);
    scanf("%s",T);

    int ns=strlen(S);
    int nt=strlen(T);

    int ans=1e9;

    for(int i=0;i<=ns-nt;i++){
        int del=0;
        for(int j=0;j<nt;j++){
            if(S[i+j]!=T[j]) del++;
        }
        ans=min(ans,del);
    }
    printf("%d\n",ans);
}
