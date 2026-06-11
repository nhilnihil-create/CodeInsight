#include<stdio.h>
char data[1300];
void proc(){
  char*p=data;
  int t='a'-'A';
  while(*p!=0){
    if('a'<=*p&&*p<='z')*p-=t;
    else if('A'<=*p&&*p<='Z')*p+=t;
    ++p;
  }
  printf("%s\n",data);
}
int main(){
  gets(data);
  proc();
  return 0;
}