#include <stdio.h>
int main(void){
    // Your code here!
    int a,b;
    a = 1;
    b = 1;
    while(a != 10 && b != 11){
        if(b != 10){
            printf("%dx%d=%d\n",a,b,a * b);
            b ++;
        }
        else{
            b = 1;
            a++;
        } 
    
    }
    return 0;
}

