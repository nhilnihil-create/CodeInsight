#include <stdio.h>

int main()
{
  int ac=0,bc=0,i,j=0, ok=0;
  char a[202],b[102];
  scanf("%s %s",a,b);
  // printf("%s %s",a,b);////////

  while(1){
    ac++;
    if(a[ac]=='\0'){
      break;
    }
  }  
  //printf("%d",ac);///
  while(1){
    bc++;
    if(b[bc]=='\0'){
      break;
    }
  }  
  //printf("%d\n",bc);////////
  for(i=0;i<ac;i++){
    a[ac+i]=a[i];
  }
  a[ac+ac]='\0';
  //printf("%s\n",a);//////// okokok
  for(i=0;i<ac+ac;i++){
    //if(a[i]==b[0]){
    for(j=0;j<bc;j++){
      if(i+j>=ac+ac){
	break;
      }
      if(b[j]!=a[i+j]){
	break;
      }
     
      // }
    if ( j == bc-1 ) ok = 1;
  }
  
}
//printf("%d\n",j);///////
//  if(j==bc-1){
if(ok == 1){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}