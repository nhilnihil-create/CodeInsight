#include <iostream>

int main(){
 int K;
 std::cin>>K;
 int A,B;
 std::cin>>A>>B;

 int count=A;
 int ans=0;
 while(count<=B){
  if(count%K==0){
   ans=1;
   break;
  }
  count++;
 }

 if(ans==1){
  std::cout<<"OK";
 }else{
  std::cout<<"NG";
 }
}