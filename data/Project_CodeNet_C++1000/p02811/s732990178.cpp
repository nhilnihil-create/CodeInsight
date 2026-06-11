#include <stdio.h>

int main(){
int K,X,results;
scanf("%d %d",&K,&X);
results = K*500;
if (results>=X){
printf("Yes\n");
}
else{
printf("No\n");
}
return 0;
}