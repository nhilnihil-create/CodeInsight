#include <stdio.h>
#define MAX 1000000
#define W 10000
#define INFTY 2000000000
int F(int,int [],int);
int main()
{
  int n,k,w[MAX]={},m,r,l,sum=0,i;
  
  scanf("%d %d",&n,&k);
  
  for(i=0;i<n;i++){
    scanf("%d",&w[i]);
  }

  w[n]=-1;
  l=0;
  r=INFTY;

  while(l<r){
    m=(l+r)/2;
    sum=F(m,w,k);
    if(sum==n && F(m-1,w,k)!=sum) break;
    if(sum<n) l=m+1;
    else if(sum==n && F(m-1,w,k)==sum) r=m;
  }

  printf("%d\n",m);

  return 0;
}

int F(int p,int w[],int k){
  int i,sum=0,s=0;
  for(i=0;i<k;i++){
    if(w[s]<=p){
      while(sum+w[s]<=p&&w[s]!=-1){
	sum+=w[s];
	s++;
      }
    }
    sum=0;
  }
  return s;
}