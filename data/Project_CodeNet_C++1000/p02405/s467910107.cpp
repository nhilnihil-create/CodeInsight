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
                        for(int t=0;t<h;t++){
                                for(int y=0;y<w;y++){
                                        if((t+y)%2) printf(".");
                                        else if((t+y)%2==0) printf("#");
                                }
                            printf("\n");
                        }
                        printf("\n");
                }
                else break;
        }
        return 0;
}