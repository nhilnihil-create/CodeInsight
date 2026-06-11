#include <stdio.h>

int main(void){
    int days[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int mo,dy;
    int day;
    
    while (scanf("%d %d", &mo, &dy)!=EOF){
        if (mo==0) break;
        day = 0;
        for (int i=1; i<mo; i++) day += days[i];
        day += dy;
        switch( day%7 ){
        case 1:
            printf("Thursday\n");
            break;
        case 2:
            printf("Friday\n");
            break;
        case 3:
            printf("Saturday\n");
            break;
        case 4:
            printf("Sunday\n");
            break;
        case 5:
            printf("Monday\n");
            break;
        case 6:
            printf("Tuesday\n");
            break;
        case 0:
            printf("Wednesday\n");
            break;
        }
    }
        
    return 0;
}