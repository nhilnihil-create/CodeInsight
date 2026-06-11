#include <stdio.h>
int main(){
int a,b;

scanf("%d",&a);scanf("%d",&b);

printf("%d %d %.5lf\n",(a/b),(a%b),((double)a/(double)b));


return 0;
}