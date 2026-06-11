#include<stdio.h>
main(){
  int a,b,ans;
  double c;
  int i;
  
  while(scanf("%d %d",&a,&b)!=EOF){
    
    c=a+b;
    
    for(i=1;i<=7;i++){
      c=c/10.0;
      if(c<1.0){
	ans=i;
	break;
      }
    }
    
    printf("%d\n",ans);
    
  }
  
  return 0;
  
}