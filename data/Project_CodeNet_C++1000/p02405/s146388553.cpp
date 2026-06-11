#include <stdio.h>
int main()
{
while(true)
{
int w,h;
scanf("%d %d", &h, &w);
if(0==h&&0==w)
break;

bool isStartSharp = true;
for(int i = 0; i < h; ++i)
{
bool isSharp = isStartSharp;
for(int j = 0; j  <w; ++j)
{
if(isSharp) printf("#");
else printf(".");
isSharp = !isSharp;
}
printf("\n");
isStartSharp = !isStartSharp;
}
printf("\n");
}
return 0;
}