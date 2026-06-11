#include <iostream>

int gcd(int a,int b){
 int r=a%b;
 while(r!=0){
  a=b;
  b=r;
  r=a%b;
 }
 return b;
}

int main(){
 int K;
 std::cin>>K;

 long long ans=0;
 for(int i=1;i<=K;i++){
  for(int j=1;j<=K;j++){
   for(int k=1;k<=K;k++){
    ans+=gcd(gcd(i,j),k);
   }
  }
 }

 std::cout<<ans;
 return 0;
}