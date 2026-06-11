#include <stdio.h> 

int main (){

int N, M;
scanf ("%d %d",&N, &M);

int x =0;
 
for (int a=1; a<N; a++){
x += a;
}

int y =0;
for (int b=1; b<M ; b++){
y += b;
}

if (N + M >=2){
    printf ("%d\n",x+y);
}
else printf ("0\n");

return 0;
}