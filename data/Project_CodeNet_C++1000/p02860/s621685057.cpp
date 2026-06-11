#include <stdio.h>

int main(){
    int n, ctr=0;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);

    for(int i=0;i<(n/2);i++){
        if (str[i] == str[i+(n/2)]){
             ++ctr;
        }
    }
    if(n%2 == 1){
        puts("No");
    } else if (ctr == (n/2)){
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}