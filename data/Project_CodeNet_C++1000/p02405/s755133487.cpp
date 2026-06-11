#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        for(;;){
            int h,w;
                scanf("%d %d",&h,&w);
                if(h){
                        for(int i=0;i<h;i++){
                                for(int j=0;j<w;j++){
                                        if((i+j)%2){
                                                printf(".");
                                        }else{
                                                printf("#");
                                        }
                                }
                                printf("\n");
                        }
                        printf("\n");
                }else{
                        break;
                }
        }
        return 0;
}