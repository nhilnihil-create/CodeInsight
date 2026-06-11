#include <stdio.h>

int main(){
    int arr[3][3];
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    int n;
    scanf("%d", &n);
    int input[n];
    for(int i = 0; i<n; i++){
        scanf("%d", &input[i]);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                if(input[i] == arr[j][k]){
                    arr[j][k] = 0;
                }
            }
        }
    }
    
    
    if((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) || (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]) || (arr[2][0] == arr[2][1] && arr[2][0]== arr[2][2]) ||
    (arr[1][1] == arr[2][2] && arr[1][1]== arr[0][0]) || (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) || (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) ||
    (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]) || (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2])){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}