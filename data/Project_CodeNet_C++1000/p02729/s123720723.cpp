#include <stdio.h>

int main(){
int N,M,Bilangan_Genap,Bilangan_Ganjil;
scanf("%d %d", &N,&M);
if (N==1 && M==1) {
printf("0\n");
}
else {
N=N-1;
M=M-1;
Bilangan_Genap=(N*(N+1))/2;
Bilangan_Ganjil=(M*(M+1)/2);
printf("%d\n",Bilangan_Genap+Bilangan_Ganjil);
}
return 0;

}