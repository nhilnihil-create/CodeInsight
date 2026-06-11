#include <stdio.h>

int main(){
    int matrix[3][3];
    char x;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int n;
    scanf("%d", &n);
    
    int input[n];
    for(int k=0; k < n; k++){
        scanf("%d", &input[k]);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(input[k] == matrix[i][j]){
                    matrix[i][j] = x;
                }
            }
        }
    }
    
    int ctr[8] = {0};
    int last=2;
    
    for(int i=0; i<3; i++){
        if(matrix[i][0]==x){
            ++ctr[0];
        }
        if(matrix[i][2]==x){
            ++ctr[1];
        }
        if(matrix[0][i]==x){
            ++ctr[2];
        }
        if(matrix[2][i]==x){
            ++ctr[3];
        }
        if(matrix[i][i]==x){
            ++ctr[4];
        } 
        if(matrix[i][last--]==x){
            ++ctr[5];
        }
        if(matrix[1][i]==x){
            ++ctr[6];
        }
        if(matrix[i][1]==x){
            ++ctr[7];
        }
    }
    
    int flag = 0;
    
    for(int i=0; i<8; i++){
        if(ctr[i] == 3){
            flag = 1;
        }
    }
    printf("%s\n", (flag == 1) ? "Yes" : "No");

    return 0;
}