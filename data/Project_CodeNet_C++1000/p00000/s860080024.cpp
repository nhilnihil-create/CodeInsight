#include <stdio.h>
 
int i, j;
int main() {
 
for(i=1; i<9+1; i++) {
for(j=1; j<9+1; j++) {
printf("%dx%d=%d\n",i,j,i*j);
}
}
 
return 0;
}