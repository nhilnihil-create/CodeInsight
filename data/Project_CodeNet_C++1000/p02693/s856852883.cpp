#include <stdio.h>
int main(){
    int multiple;
    int start;
    int end;
    scanf("%d", &multiple);
    scanf("%d %d", &start, &end);
    int length = end - start;
    int count;
    for(int i = 0; i <= length ; i++){
        int total = start % multiple;
        start++;
        if(total == 0){
            count++;
        }
        else{
            count = count + 0;;
        }
    }
    if(count > 0){
        printf("OK\n");
    }
    else{
        printf("NG\n");
    }
    return 0;
}