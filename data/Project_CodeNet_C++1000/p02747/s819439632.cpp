#include <stdio.h>
#include <string.h>
 
int main(){
  int i;
  char a[512];
  int chk=0;
  scanf("%s",a);
  if(strlen(a)%2!=0)chk=1;
  for(i=0;i<strlen(a);i+=2){
    if(a[i]!='h' || a[i+1]!='i')chk=1;
  }
  if(chk==0){
    printf("Yes\n");
  }else{
	printf("No\n");
  }
  return 0;
}