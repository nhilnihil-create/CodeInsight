#include<stdio.h>
#include<ctype.h>
int main(){
  int cnt[150]={0};
  int i,c;
  while((c=getchar())!=EOF){
    if(isupper(c)){
      c=tolower(c);
    }
    cnt[c]++;
  }
  for(i=97;i<=122;i++){
    printf("%c : %d\n",i,cnt[i]);
  }
}