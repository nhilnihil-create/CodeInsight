#include<stdio.h>
main(){int i=1,j=1;for(;;){printf("%dx%d=%d\n",i,j,i*j);j++;if(j==10){i++;j=1;}if(i==10){break;}}}