#include<cstdio>
int i,j;
main(){
    for(;i++<9;)for(j=1;j<10;)printf("%dx%d=%d\n",i,j++,i*j);
}