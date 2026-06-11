#include <stdio.h>

int main() {
	int n;
    scanf("%d", &n);
    int temp = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i * j == n){
                temp = 1;
                break;
            }
        }
    }
    if(temp == 1){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}