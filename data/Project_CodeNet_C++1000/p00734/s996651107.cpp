#include <stdio.h>
int main()
{
  int ta[100],ha[100],ts,hs,t,h,at,ah,min,i,j;
  while(1){
    scanf("%d %d",&t,&h);
    if(t==0&&h==0)break;
    hs=0;
    ts=0;
    for(i=0;i<t;i++){
      scanf("%d",&ta[i]);
      ts+=ta[i];
    }
    for(i=0;i<h;i++){
      scanf("%d",&ha[i]);
      hs+=ha[i];
    }
    ///printf("%d %d %d %d\n",ts,hs,t,h);///
    min=10000;
    at=-100;
    ah=-100;
    for(i=0;i<t;i++){
      for(j=0;j<h;j++){
	if(ts-ta[i]+ha[j]==hs-ha[j]+ta[i]){
	  if(ta[i]+ha[j]<min){
	    at=ta[i];
	    ah=ha[j];
	    min=ta[i]+ha[j];
	  }
	}
      }
    }
    if(at!=-100&&ah!=-100)printf("%d %d\n",at,ah);
    else  printf("-1\n");
  }
  return 0;
}