#include <stdio.h>

int main(){
int a1,a2,a3,score;
scanf("%d %d %d", &a1,&a2,&a3);
score=a1+a2+a3;
if (score>=22) {
printf("bust\n");
}
else {
printf("win\n");
}

return 0;
}
