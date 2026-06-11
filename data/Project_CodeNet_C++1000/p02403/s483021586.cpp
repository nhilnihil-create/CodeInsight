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
                cin>>h>>w;
                if(h==0 && w==0) break;
                for(int j=0;j<h;j++){
                        for(int k=0;k<w;k++){
                                printf("#");
                        }
                        printf("\n");
                }
                printf("\n");
        }
        return 0;
}