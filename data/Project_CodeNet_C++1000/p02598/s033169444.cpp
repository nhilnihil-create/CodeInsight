#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,i,a[200010],sum;
  int lh,rh=0,mid;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){scanf("%d",&a[i]);rh=max(rh,a[i]);}
  
  lh=0;
  while(rh!=lh+1){
    mid=(rh+lh)/2;
    sum=0;
    for(i=0;i<n;i++){sum += (a[i]-1)/mid;}
    if(sum<=k){
      rh = mid;
    }else{
      lh = mid;
    }
//    printf("%d %d\n",lh,rh);
  }
  printf("%d\n",rh);
  return 0;
}