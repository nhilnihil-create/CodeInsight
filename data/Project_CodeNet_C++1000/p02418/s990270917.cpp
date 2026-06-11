#include <stdio.h>
#include <string.h>
int main(){
  char s[100],p[100],r[200];
  scanf("%s",s);
  scanf("%s",p);
  strcpy(r,s);
  strcat(r,s);
  if(strstr(r,p)){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}