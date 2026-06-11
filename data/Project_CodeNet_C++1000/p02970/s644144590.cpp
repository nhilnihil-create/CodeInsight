/* ex4_1
  sachiyan */

#include <stdio.h>
int main(void){
    int number, watched;
    int answer;
    scanf("%d %d", &number, &watched);
    if( number % (2*watched+1) != 0){
        answer = number / (2*watched+1) + 1;
        printf("%d\n", answer);
    }
    else{
        answer = number / (2*watched+1);
        printf("%d\n", answer);
    }


    return 0;
}
