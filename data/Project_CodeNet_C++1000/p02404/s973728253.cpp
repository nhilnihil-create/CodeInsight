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
                if(i==0 || i==tate-1) printf("#");
                else if(j==0 || j==yoko-1) printf("#");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}