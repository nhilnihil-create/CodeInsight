#include<stdio.h>
 
 
int main(){
 
    int A[3][3], x , B[10], check[3][3];
 
    for(int i = 0 ; i < 3 ; i++ ) {
        scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
    }
 
    scanf("%d",&x);
    
    for(int j = 0 ; j < x ; j++ ){
        scanf("%d",&B[j]);
 
        for(int  l = 0 ; l < 3 ; l++ ) {
            for(int k = 0 ; k < 3 ; k++ ){
                if( B[j] == A[l][k] ) {
                    check[l][k] = 1;
                }
            }   
        }
    }   
    
    if( (check[1][1] == 1 && check[2][2] == 1 && check[0][0] == 1  )
    || (check[2][0] == 1 && check[1][1] == 1 && check[0][2] == 1  )
    || (check[0][0] == 1 && check[0][1] == 1 && check[0][2] == 1  )
    || (check[1][0] == 1 && check[1][1] == 1 && check[1][2] == 1  )
    || (check[2][0] == 1 && check[2][1] == 1 && check[2][2] == 1  )
    || (check[0][0] == 1 && check[1][0] == 1 && check[2][0] == 1  )
    || (check[0][1] == 1 && check[1][1] == 1 && check[2][1] == 1  )
    || (check[0][2] == 1 && check[1][2] == 1 && check[2][2] == 1  )
    ) {   
        printf("Yes\n");
    } else {
        printf("No\n");
    }
 
        return 0;
}