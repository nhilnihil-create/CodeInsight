#include <stdio.h>
#include <string.h>
#define ll long long int

int main(){
int h1,m1,h2,m2,d;
scanf("%d %d %d %d %d",&h1,&m1,&h2,&m2,&d);
int hminutes = (h2-h1) * 60;
int mminutes = m2-m1;
int tminutes = hminutes + mminutes;
int res = tminutes - d;
printf("%d",res);
return 0;
}
