#include <stdio.h>
int main()
{
  int kls[4][13],n,h,w,kn,cou,hw,kcn;
  char kc[2],hh;
  for(h=0;h<4;h++){
    for(w=0;w<13;w++){
      kls[h][w]=0;
    }
  }
  scanf("%d",&n);
  for(cou=0;cou<n;cou++){
    scanf("%s %d",kc,&kn);
    if(kc[0]=='S'){
      kcn=0;
    }else
      if(kc[0]=='H'){
	kcn=1;
      }else
	if(kc[0]=='C'){
	  kcn=2;
	}else
	  if(kc[0]=='D'){
	    kcn=3;
	  }
    kn=kn-1;
    kls[kcn][kn]=1;
  }
  for(h=0;h<4;h++){
    for(w=0;w<13;w++){
      if(kls[h][w]==0){
	if(h==0){
	  hh='S';
	}else
	  if(h==1){
	    hh='H';
	  }else
	    if(h==2){
	      hh='C';
	    }else
	      if(h==3){
		hh='D';
	      }
	hw=w+1;
	printf("%c %d\n",hh,hw);
      }
    }
  }
  return 0;
}