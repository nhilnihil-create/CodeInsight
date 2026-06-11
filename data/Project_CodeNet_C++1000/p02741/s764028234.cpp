#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k;
    scanf("%d", &k);
    if(k==1||k==2||k==3||k==5||k==7||k==11||k==13||k==15||k==17||k==19||k==23||k==29||k==31){
        printf("%d", 1);
    } else if (k==4||k==6||k==9||k==10||k==14||k==21||k==22||k==25||k==26){
        printf("%d", 2);
    } else if (k==8||k==12||k==18||k==20||k==27){
        printf("%d", 5);
    } else if (k==28||k==30){
        printf("%d", 4);
    } else if (k==16){
        printf("%d", 14);
    } else if(k==24){
        printf("%d", 15);
    } else {
        printf("%d", 51);
    }
    
    return 0;
}
