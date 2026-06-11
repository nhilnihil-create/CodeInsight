#include <cstdio>
#include <stdlib.h>
int main(void)
{
char s[500];
double r;
scanf("%s",s);
r=atof(s);
printf("%f %f\n", r*r*3.14159265358979323, 3.14159265358979323*2*r);
return 0;
}