#include <stdio.h>

int main (){
    int a[5][5];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int b[5][5] = {};
    int banyak;
    scanf("%d", &banyak);
    int input;
    for(int i = 0; i <= banyak; i++){
        scanf("%d", &input);
        for(int i = 0; i< 3; i++){
            for(int j = 0; j < 3; j++){
                if(input == a[i][j]){
                    b[i][j]++;
                    if((b[0][0] > 0 && b[0][1] > 0 && b[0][2] > 0) || (b[1][0] > 0 && b[1][1] > 0 && b[1][2] > 0) || (b[2][0] > 0 && b[2][1] > 0 && b[2][2] > 0) || (b[0][0] > 0 && b[1][0] > 0 && b[2][0] > 0) || (b[0][1] > 0 && b[1][1] > 0 && b[2][1] > 0) || (b[0][2] > 0 && b[1][2] > 0 && b[2][2] > 0) || (b[0][2] > 0 && b[1][1] > 0 && b[2][0] > 0) || (b[0][0] > 0 && b[1][1] > 0 && b[2][2] > 0)){
                        printf("Yes");
                        return 0;
                    } 
                }
            }
        }
    }
    printf("No");    


    return 0;
}