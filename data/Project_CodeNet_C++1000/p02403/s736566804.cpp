#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int tate=1,yoko=1;
    while(1){
        cin>>tate>>yoko;
        if(tate==0 && yoko==0)break;
        for(int i=0;i<tate;i++) {
            for(int j=0;j<yoko;j++) {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}