#include <stdio.h>


int main () {
    int N;  
	scanf("%d", &N);
    char str[N + 1];
    scanf("%s", str);
    if (N % 2 == 1) {
        printf("No");
    }
    else {
        int flag = 1;
        for (int i = 0; i < N / 2; i++){
            if (str[i] != str[i + N / 2]){
                flag = 0;
            }
        }
        if (flag){
            printf("Yes");
        }
        else {
            printf("No");
        }
    }
    return 0;
}