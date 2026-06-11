#include<cstdio>
main(){for(int i,c,k,n,j;scanf("%d",&n)+1;k=0){for(i=0;i<1e4;c=0){for(j=i++;j>0;j/=10)c+=j%10;c-n?k:k++;}printf("%d\n",k);}}