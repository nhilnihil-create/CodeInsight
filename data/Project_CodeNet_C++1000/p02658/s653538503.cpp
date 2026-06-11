#include<stdio.h>
 
int main(){
  long long n,ans=1;
  scanf("%lld",&n);
  long long arr[n+5],maks=1000000000000000000;
  for(long long i=1;i<=n;i++){
      scanf("%lld",&arr[i]);}
  
  for(int i=1;i<=n;i++){
    if(arr[i]==0){
        printf("0");
        return 0;
    }
  }
  
  for(long long i=1;i<=n;i++){
    if(maks/ans<arr[i]){
        printf("-1");
        return 0;
    }
    
    ans*=arr[i];
  }
  
  printf("%lld",ans);
}