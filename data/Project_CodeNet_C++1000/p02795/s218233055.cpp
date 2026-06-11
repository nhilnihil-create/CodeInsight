#include <stdio.h>

int main() {
    int x, y, n;
    scanf("%d%d%d", &x,&y,&n);
    int count1 = 0;
    int count2 = 0;
    int temp1 = 0;
    int temp2 = 0;
    for (int i=1; i<=x; i++){
        count1++;
        temp1 += y;
        if (temp1 >= n){
            break;
        }
    }
    for (int i=1; i<=y; i++){
        count2++;
        temp2 += x;
        if (temp2 >= n){
            break;
        }
    }
    if (count1 <= count2){
        printf("%d\n", count1);
    }
    else{
        printf("%d\n", count2);
    }
    return 0;
}