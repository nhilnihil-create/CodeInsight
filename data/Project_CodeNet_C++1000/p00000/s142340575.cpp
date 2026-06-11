#include<cstdio>
int main(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
}