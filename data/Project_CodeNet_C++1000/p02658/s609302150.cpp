#include<stdio.h>

int main () {
long long int t, sum =1;
scanf("%lld",&t);

long long int n[t];
for(int i=0;i<t;i++){
    scanf("%lld",&n[i]);
}
for(int i=0; i<t; i++){
  if (n[i] ==0 ){
    printf("0");
    return 0;
  }

}
for (int i=0; i<t;i++){
  if(n[i] <=1000000000000000000 /sum){
    sum *= n[i];
  }
  else{
    printf("-1");
    return 0;
  }
}
printf("%lld",sum);
return 0;
}
