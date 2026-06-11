#include<stdio.h>
#include<string.h>
int flag[20][20];//?????°?????????0
char map[20][21];//y:x
int count;
int H,W;
void search(int nx,int ny);
main(){
    scanf("%d%d",&W,&H);
    while(H){
        memset(flag,0,sizeof(flag));
        memset(map,0,sizeof(map));
        for(int i = 0;i < H;i++){
            scanf("%s",map[i]);
        }
        for(int i = 0;i < H;i++){
            for(int j = 0;j < W;j++){
                if(map[i][j] == '@'){
                    count = 0;
                    search(j,i);
                    printf("%d\n",count);
                }
            }
        }
        scanf("%d%d",&W,&H);
    }
}
void search(int nx,int ny){
    if(nx<0 || ny<0 || nx>W-1 || ny>H-1){
        return;
    }
    if(map[ny][nx] == '#'){
        return;
    }
    if(flag[ny][nx] == 0){
        flag[ny][nx]++;
        count++;
        search(nx+1,ny);
        search(nx-1,ny);
        search(nx,ny+1);
        search(nx,ny-1);
    }
}