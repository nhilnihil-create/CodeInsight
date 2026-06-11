#include <stdio.h>

int main(){
char previous[3];
scanf("%s", previous);
if(previous[1]=='B')printf("ARC\n");
else if(previous[1]=='R')printf("ABC\n");
return 0;
}