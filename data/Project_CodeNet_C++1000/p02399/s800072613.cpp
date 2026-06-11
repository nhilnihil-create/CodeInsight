#include<stdio.h>
#include<stdlib.h>

int main()
{
  char str[20],x[20],y[20];
  int a,b,i=0,j=0;
  int d,r;
  double f;
 
  fgets(str,sizeof(str),stdin);
  
  for(;;){
    if(str[i]==' '){
      break;
    }
    x[i]=str[i];
    i++;
  }
  
  for(;;){
    if(str[i]=='\0'){
      break;
    }
    y[j]=str[i];
    i++;
    j++;
  }
  a=atoi(x);
  b=atoi(y);
  
  if(a<1 || 1000000000<b){
    printf("Error!!\n");
  }else{
    d=a/b;
    r=a%b;
    f=(double)a/(double)b;
    printf("%d %d %f\n",d,r,f);
  }
  return 0;
}