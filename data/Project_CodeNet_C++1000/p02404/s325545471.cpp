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
                        for(int x=0;x<h;x++){
                                if(x==0 || x==h-1){
                                for(int i=0;i<w;i++){
                                        printf("#");
                                }
                                printf("\n");
                                }else{
                                        for(int i=0;i<w;i++){
                                                if(i==0 || i==w-1){
                                                        printf("#");
                                                }else{
                                                        printf(".");
                                                }
                                        }
                                        printf("\n");
                                }
                        }
                printf("\n");
                }else{
                        break;
                }
        }
        return 0;
}