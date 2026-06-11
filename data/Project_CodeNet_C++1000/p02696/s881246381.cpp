#include <iostream>

int main(){
 long long A,B,N;
 std::cin>>A>>B>>N;

 long long x=0;
 if(B<=N){
  x=B-1;
 }else{
  x=N;
 }
 long long ans=(A*x)/B;
 ans-=(x/B)*A;

 std::cout<<ans<<std::endl;
}