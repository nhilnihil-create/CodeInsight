#include<stdio.h>
int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a<=b&&b<=c)printf("%d %d %d\n",a,b,c);
  if(a>b&&a< c)printf("%d %d %d\n",b,a,c);
  if(b> c&&a< b)printf("%d %d %d\n",a,c,b);
  if(a> c&&b< a&&b>=c)printf("%d %d %d\n",c,b,a);
  if(a>b&&b<c&&c<a)printf("%d %d %d\n",b,c,a);
  return 0;
}