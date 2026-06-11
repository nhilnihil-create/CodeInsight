#include <stdio.h>

int main(void)
{
    int A[3][3],N;
    int b[100];
    int x,y;
    int i;
    int ret = 0;
    for( i = 0 ; i < 3 ; i++){
        scanf("%d %d %d",&(A[0][i]),&(A[1][i]),&(A[2][i]));
    }
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++){
        scanf("%d",&(b[i]));
        //穴をあける(-1にする)
        for( y = 0 ; y < 3 ; y++){
            for( x = 0 ; x < 3 ; x++){
                if(A[x][y] == b[i]){
                    A[x][y] = -1;
                    break;
                }
            }
        }
    }
    //縦横方向チェック
    for(i = 0 ; i < 3 ; i++){
        if(A[0][i] + A[1][i] + A[2][i] == -3) ret++;
        if(A[i][0] + A[i][1] + A[i][2] == -3) ret++;
    }
    //斜めチェック
    if(A[0][0] + A[1][1] + A[2][2] == -3) ret++;
    if(A[2][0] + A[1][1] + A[0][2] == -3) ret++;
    if(ret > 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}