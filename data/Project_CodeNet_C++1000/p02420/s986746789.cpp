#include<stdio.h>
#include<string.h>
int main(){
  int h,m,n,i,j,k,len;
  char work;
  char s[200];
  while(1){
    scanf("%s",s);
    len=strlen(s);
    if(s[0]=='-')break;
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%d",&h);
      for(j=0;j<h;j++){
        work=s[0];
        for(k=0;k<len-1;k++){
          s[k]=s[k+1];
        }
        s[len-1]=work;
      }
    }
    printf("%s\n",s);
  }
  return 0;
}