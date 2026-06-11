#include <stdio.h>

int main(){
    int h,w,n;
    scanf("%d %d %d", &h, &w, &n);
    int ans;

    if(n/h > n/w){
        if(n%w == 0){
            ans = n/w;
        } else {
            ans = n/w+1;
            } 
    } else {
        if(n%h == 0){
            ans = n/h;
        } else {
            ans = n/h+1;
        }
    }
    printf("%d\n", ans);
return 0;
}