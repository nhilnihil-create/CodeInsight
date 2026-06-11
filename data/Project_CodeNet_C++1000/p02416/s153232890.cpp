#include<stdio.h>
char data[1010];
void proc(){
  int sum=0;
  char*p=data;
  while(*p!=0){
    sum+=*p-'0';
    ++p;
  }
  printf("%d\n",sum);
}
int main(){
  while(true){
    gets(data);
    if(data[0]=='0')break;
    proc();
  }
  return 0;
}