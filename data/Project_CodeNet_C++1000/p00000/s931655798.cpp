#include<stdio.h>
main(){int i=1,j=1;for(;i!=10;j++){printf("%dx%d=%d\n",i,j,i*j);if(j==9){i++;j=0;}}}