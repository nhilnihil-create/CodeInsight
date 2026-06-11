#include<iostream>
#include<stdio.h>
using namespace std;
 
int main(){
    while(1){
        int H,W;
        cin >> H >>W;
         
        if(H==0 && W==0)break;
        for(int y=0;y<H;y++){
            for(int x=0;x<W;x++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
     
    return 0;
}