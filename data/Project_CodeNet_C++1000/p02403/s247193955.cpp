#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        for(;;){
                int H,W;
                scanf("%d %d",&H,&W);
                if(H){
                        for(int i=0;i<H;i++){
                                for(int j=0;j<W;j++){
                                        printf("#");
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