#include <stdio.h>
int insert(int *,int,int);
void shell(int *,int);
int main(){
  int i,a[1000000],n;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  shell(a,n);
  return 0;
}
int insert(int *a,int n,int g){
  int i,j,v,cnt=0;
  for(i=0;i<n;i++){
    v=a[i];
    j=i-g;
    while(j>=0 && a[j]>v){
      a[j+g]=a[j];
      j=j-g;
      cnt++;
    }
    a[j+g]=v;
  }
  return cnt;
}
void shell(int *a,int n){
  int m,g[100],i,j,array,cnt=0;
  g[0]=1;
  for(m=1;m<100;m++){
    if(g[m-1]*3+1>=n)break;
    g[m]=g[m-1]*3+1;
  }
 
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
  printf("%d ",g[i]);
  if(i!=0)printf(" ");
   }
  printf("\n");
  for(i=m-1;i>=0;i--)cnt+=insert(a,n,g[i]);
  printf("%d\n",cnt);
  for(i=0;i<n;i++)printf("%d\n",a[i]);
}

