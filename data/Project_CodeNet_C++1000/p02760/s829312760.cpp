#include <stdio.h>

int main (){
    int a[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int ce[3][3] = {};
    int n;
    scanf("%d", &n);
    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(x == a[j][k]){
                    ce[j][k]++;
                    if((ce[0][0] > 0 && ce[0][1] > 0 && ce[0][2] > 0) || (ce[1][0] > 0 && ce[1][1] > 0 && ce[1][2] > 0) || (ce[2][0] > 0 && ce[2][1] > 0 && ce[2][2] > 0) || (ce[0][0] > 0 && ce[1][0] > 0 && ce[2][0] > 0) || (ce[0][1] > 0 && ce[1][1] > 0 && ce[2][1] > 0) || (ce[0][2] > 0 && ce[1][2] > 0 && ce[2][2] > 0) || (ce[0][2] > 0 && ce[1][1] > 0 && ce[2][0] > 0) || (ce[0][0] > 0 && ce[1][1] > 0 && ce[2][2] > 0)){
                        puts("Yes");
                        return 0;
                    } 
                }
            }
        }
    }
    puts("No");    


    return 0;
}