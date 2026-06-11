#include <stdio.h>

int main(){

    int array[10][10];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &array[i][j]);
        }
    }
/*    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
*/
    int brpKali;
    scanf("%d", &brpKali);
    int percobaan[100];
    for(int k=0;k<brpKali;k++){
        scanf("%d", &percobaan[k]);
    }
/*    for(int k=0;k<brpKali;k++){
        printf("%d", percobaan[k]);
    }
*/

    for(int l=0;l<brpKali;l++){
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                if(percobaan[l]==array[m][n]){
                    array[m][n]=0;
                }
            }
        }
    }

if(array[0][0]+array[1][1]+array[2][2]==0){
        printf("Yes\n");
    }
    else if(array[0][2]+array[1][1]+array[2][0]==0){
        printf("Yes\n");
    }
    else if(array[0][0]+array[0][1]+array[0][2]==0){
        printf("Yes\n");
    }
    else if(array[1][0]+array[1][1]+array[1][2]==0){
        printf("Yes\n");
    }
    else if(array[2][0]+array[2][1]+array[2][2]==0){
        printf("Yes\n");
    }
    else if(array[0][0]+array[1][0]+array[2][0]==0){
        printf("Yes\n");
    }
    else if(array[0][1]+array[1][1]+array[2][1]==0){
        printf("Yes\n");
    }
    else if(array[0][2]+array[1][2]+array[2][2]==0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }


    return 0;
}