#include<stdio.h>
#include<string.h>
int main(){
  char ARF[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char arf[27]="abcdefghijklmnopqrstuvwxyz";
  char s1[11],s2[1001];
  int i,j,sum=0;
  scanf("%s",s1);
  while(1){
    scanf("%s",s2);
    if(strcmp("END_OF_TEXT",s2)==0) break;
    int len=strlen(s2);
    for(i=0;i<len;i++){
      if(s2[i]<91){
	for(j=0;j<26;j++){
	  if(s2[i]==ARF[j]){
	    s2[i]=arf[j];
	  }
	}
      }
    }
    if(strcmp(s1,s2)==0){
      sum++;
    }
  }
  printf("%d\n",sum);
  return(0);
}