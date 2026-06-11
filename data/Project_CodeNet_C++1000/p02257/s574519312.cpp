#include<stdio.h>
#include<math.h>
main(){
  int n,num;
  int i,j;
  int ans = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num);
    for(j=2;j<=sqrt(num*1.0)+1;j++){
      if(num%j==0){
        ans--;
        break;
      }
    }
    ans++;
    if(num==2){
      ans++;
    }
  }
  printf("%d\n",ans);
}