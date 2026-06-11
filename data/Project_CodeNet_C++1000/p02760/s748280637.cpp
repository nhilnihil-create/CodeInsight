#include <stdio.h>

int main(){
    int grid[3][3], b, verify[3][3]={0}, n;

    for(int i = 0; i < 3; i++){ 
        for(int j = 0; j < 3; j++){
            scanf("%d", &grid[i][j]);
        }                            
    }

    scanf("%d",&n);
    for(int k = 0; k < n; k++){
        scanf("%d",&b);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] == b)
                {
                    verify[i][j] = 1;
                }
            }
        }
    }
    if(verify[0][0] + verify[1][1] + verify[2][2] == 3 || verify[0][2] + verify[1][1] + verify[2][0] == 3){
        printf("Yes\n");
        return 0;
    }
    for(int i = 0; i < 3; i++){
        if(verify[i][0] + verify[i][1] + verify[i][2] == 3 || verify[0][i] + verify[1][i] + verify[2][i] == 3){

            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");

    return 0;
}