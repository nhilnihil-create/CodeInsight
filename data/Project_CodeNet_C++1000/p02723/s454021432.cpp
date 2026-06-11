#include<stdio.h>
typedef long long int lli;
int main() {
  char s[6];
  scanf("%s", &s);
 
  if(s[2]==s[3] && s[4]==s[5]){
      printf("Yes\n");
  }
  else{
      printf("No\n");
  }
  return 0;
}