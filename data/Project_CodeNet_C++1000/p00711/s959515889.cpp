

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int w,h;
char map[21][21];
int dfs(int si,int sj){
    int ans=1;
    if(si<=-1||si>=h)return 0;
    if(sj<=-1||sj>=w)return 0;
    if(map[si][sj]=='#') return 0;
    map[si][sj]='#';
    ans+=dfs(si+1,sj);
    ans+=dfs(si,sj+1);
    ans+=dfs(si-1,sj);
    ans+=dfs(si,sj-1);
    return ans;
}


int main(){
    while(1){
        scanf("%d %d",&w,&h);
        if(w==0 && h==0)break;
        int i,j,si=0,sj=0;
        for(i=0;i<=h-1;i++){
        scanf("%s",map[i]);
        }
        for(i=0;i<=h-1;i++){
            for(j=0;j<=w-1;j++){
                if(map[i][j]=='@'){
                    si=i;
                    sj=j;
                }
            }
        }
        printf("%d\n",dfs(si,sj));
        }
    return 0;
}