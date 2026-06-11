#include <stdio.h>

int main(){
int K,R;
scanf("%d %d",&K,&R);
if (K>=10){
printf("%d\n", R);
}
else {
printf("%d\n", R+(100 * (10-K)));
}
return 0;
}