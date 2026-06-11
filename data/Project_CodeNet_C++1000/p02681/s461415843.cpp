#include<stdio.h>
#include<string.h>

int main(){
  char s[100], t[100];
  scanf("%s %s", s, t);

  if(strncmp(s, t, strlen(s))!=0){
    printf("No\n");
  }else{
    if(strlen(t)!=strlen(s)+1)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
