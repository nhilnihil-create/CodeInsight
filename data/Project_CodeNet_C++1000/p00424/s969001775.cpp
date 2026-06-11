#include<cstdio>
#include<iostream>
int main(){
    while(1){
    int n,m;
    char change[2][1000];
    char bass;
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            scanf(" %c %c",&change[0][i],&change[1][i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf(" %c",&bass);
            for(int j=0;j<n;j++){
                if(bass==change[0][j]){
                    bass=change[1][j];
                    break;
                }
            }
            printf("%c",bass);
        }
        puts("");
    }
    return 0;
}