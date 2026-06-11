#include<cstdio>
main(){
 int a,b;
 while(1){
  scanf("%d%d",&a,&b);
  if(!a&&!b)break;
  else if(a>b){
   int buf;
   buf = a;
   a = b;
   b = buf;
  }
  printf("%d %d\n",a,b);
 }
}