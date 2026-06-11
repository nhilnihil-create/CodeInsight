#include <cstdio>
int main(void)
{
  while(1){
    int n;
    scanf("%d",&n);
    if(!n) break;
    int ap=0,bp=0;
    for(int i=0;i<n;i++){
      int a,b;
      scanf("%d %d",&a,&b);
      if(a > b) ap+=a+b;
      else if(a < b) bp+=a+b;
      else { 
	ap += a;
	bp += b;
      }
    }
    printf("%d %d\n",ap,bp);
  }
}