#include <stdio.h>
#include <string.h>
main(){
  char s[13],t[13];scanf("%s%s",s,t);t[strlen(t)-1]='\0';
  puts(!strcmp(s,t)?"Yes":"No");
}