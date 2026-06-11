#include <stdio.h>
#include <string.h>
int main(){
    
    int arr[3][3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int X;
    scanf("%d", &X);
    int numb[X]={0};
    
    for (int k=0;k<X;k++){
        scanf("%d", &numb[k]);
        for(int l=0;l<3;l++){
            for(int m=0;m<3;m++){
                if(numb[k] == arr[l][m]){
                    arr[l][m] = 0;
                }
            }
        }
    }
    if(arr[0][0]==0 && arr[0][1]==0 && arr[0][2]==0){
        printf("Yes");
    } else if(arr[1][0]==0 && arr[1][1]==0 && arr[1][2]==0){
        printf("Yes");
    } else if(arr[2][0]==0 && arr[2][1]==0 && arr[2][2]==0){
        printf("Yes");
    } else if(arr[0][0]==0 && arr[1][0]==0 && arr[2][0]==0){
        printf("Yes");
    } else if(arr[0][1]==0 && arr[1][1]==0 && arr[2][1]==0){
        printf("Yes");
    } else if(arr[0][2]==0 && arr[1][2]==0 && arr[2][2]==0){
        printf("Yes");
    } else if(arr[0][0]==0 && arr[1][1]==0 && arr[2][2]==0){
        printf("Yes");
    } else if(arr[0][2]==0 && arr[1][1]==0 && arr[2][0]==0){
        printf("Yes");
    } else {
        printf("No");    
    }
    
    return 0;
}
 