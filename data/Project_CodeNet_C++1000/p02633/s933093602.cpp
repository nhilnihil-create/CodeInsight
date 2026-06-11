//T - Problem 20(indu)
#include <bits/stdc++.h>
using namespace std;

#define last 360

int main(){

    int angle{0};
    scanf("%d",&angle);
    
    int mul{last};
    
    for(int i = 1; i <= angle; i++){
        if(angle % i == 0 && last % i == 0){
            mul =(int) last/i;
        }
    }
    
    printf("%d\n",mul);
    
    return 0;
}