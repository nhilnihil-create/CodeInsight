#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int mx,score[2]={},input;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cin>>input;
            score[i]+=input;
        }
    }
    mx=(score[0]>score[1])?score[0]:score[1];
    printf("%d\n",mx);
    return 0;
}