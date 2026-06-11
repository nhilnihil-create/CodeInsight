#include <stdio.h>
int main()
{
  int box[101][101],r,c,cour,couc,sumc,sumr=0,suma=0;
  scanf("%d %d",&r,&c);
  for(cour=1;cour<r+1;cour++){
    for(couc=1;couc<c+1;couc++){
      scanf("%d",&box[cour][couc]);
    }
  }
  for(cour=1;cour<r+1;cour++){
    sumc=0;
    for(couc=1;couc<c+2;couc++){
      if(couc<c+1){
	printf("%d ",box[cour][couc]);
	sumc=sumc+box[cour][couc];
      }
    }
    printf("%d\n",sumc);
  }
  for(couc=1;couc<c+1;couc++){
    sumr=0;
    for(cour=1;cour<r+1;cour++){
      sumr=sumr+box[cour][couc];
    }
    printf("%d ",sumr);
    suma=suma+sumr;
  }
  printf("%d\n",suma);
  return 0;
}