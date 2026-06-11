#include "stdio.h"
#include "math.h"


int i,j,k;
int in;
int cnt=0;
int data[3000][1000];
int ps[3000];
int sum[3000]={0};
double av[3000];
double ans[3000];

int main(){
  do{
    scanf("%d",&in);
    ps[cnt]=in;
    for(i=0;i<in;i++){
      scanf("%d",&data[cnt][i]);
      sum[cnt]+=data[cnt][i];
    }
    cnt++;
  }while(in!=0);
  cnt--;
  
  for(i=0;i<cnt;i++){
    av[i]=(double)sum[i]/(double)ps[i];
  }
  for(i=0;i<cnt;i++){
    double tmp=0;
    for(j=0;j<ps[i];j++){
      tmp+=(double)(data[i][j]-av[i])*(double)(data[i][j]-av[i]);
    }
    ans[i]=sqrt((double)tmp/(double)ps[i]);
  }
  
  for(i=0;i<cnt;i++){
    printf("%.8lf\n",ans[i]);
  }
  
  return 0;
}