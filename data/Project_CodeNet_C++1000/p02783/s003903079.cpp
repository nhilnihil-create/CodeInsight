#include <stdio.h>

int main(){

    int H;
    int A;

    scanf("%d %d", &H, &A);

    if(H % A == 0){
        printf("%d\n", H / A);
}
    else{
        printf("%d\n", (H / A) + 1);
    }

    return 0;

}