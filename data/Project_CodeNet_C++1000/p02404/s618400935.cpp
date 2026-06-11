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
                if(!h) break;
                for(int i=0;i<w;i++){
                    printf("#");
                }
                printf("\n");
                for(int i=0;i<h-2;i++){
                        printf("#");
                        for(int j=0;j<w-2;j++){
                                printf(".");
                        }
                        printf("#");
                        printf("\n");
                }
                for(int i=0;i<w;i++){
                    printf("#");
                }
            printf("\n");
            printf("\n");

        }
        return 0;
}