#include <stdio.h>

int main(){
  int i,j,k;
  int n;
  scanf("%d",&n);
  int L[150];
  int ans = 0;
  for(i=0;i<n;++i){
    scanf("%d",&L[i]);
  }
  
  for(i=0;i<n;++i){
    for(j=0;j<n-1;j++){
      int a = L[j], b = L[j+1];
      if(a<b){
        L[j]=b;
        L[j+1]=a;
      }
    }
  }
  
  for(i=0;i<n;++i){
    for(j=i+1;j<n;++j){
      for(k=j+1;k<n;++k){
        if(L[i]>=L[j]+L[k])continue;
        if(L[i]==L[j])continue;
        if(L[j]==L[k])continue;
  		ans++;      
      }
    }
  }
  
  printf("%d\n",ans);
}
