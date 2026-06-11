#include<stdio.h>
#include<string.h>
char data[1000];
char s[1000];
int main(){
  gets(data);
  strcat(s,data);
  strcat(s,data);
  gets(data);
  char*p=s;
  int len=strlen(data);
  while(*p!=0){
    if(!strncmp(p,data,len)){
      printf("Yes\n");
      return 0;
    }
    ++p;
  }
  printf("No\n");
  return 0;
}