#include <stdio.h>


int main(){

    int n,left = 0,right = 0;
    scanf("%d", &n);
    char str[10000];
    scanf("%s", str);
    int mid = n/2;
    if(n % 2 != 0){
    puts("No");
    return 0;
    }
for(int i= 0; i < mid ; i++ ){
    left += str[i];
}
for(int i = mid; i < n; i++){
    right += str[i];
}

if(right == left){
    printf("Yes\n");

}else {
    printf("No\n");
}

    return 0;
}