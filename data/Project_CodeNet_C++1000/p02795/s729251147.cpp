#include <stdio.h>

int main() {
    int h,w,n;
    scanf("%d", &h);
    scanf("%d", &w);
    scanf("%d", &n);
    int counter = 0;
    int sum = 0;
    while (n > sum){
        if(w >= h){
            sum += w;
            counter++;
        }else if(h > w){
            sum+= h;
            counter++;
        }
    }
    printf("%d\n",counter);
    
    return 0;
}