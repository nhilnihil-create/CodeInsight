#include <stdio.h>
#include <string.h>

int main(){
int A,B;
char S[100],T[100],U[100];

scanf("%s %s", &S,&T);
scanf("%d %d", &A, &B);
scanf("%s", &U);
if (strcmp(S,U)==0){
printf("%d %d",A-1,B);
}
else if (strcmp(T,U)==0){
printf("%d %d",A,B-1);
}
else {
printf("%d %d",A,B);
}

return 0;
}