#include <iostream>

int main(){
 int N,M;
 std::cin>>N>>M;
 int* A=new int[M];
 for(int i=0;i<M;i++){
  std::cin>>A[i];
 }
 
 int sum=0;
 for(int i=0;i<M;i++){
  sum+=A[i];
 }
 int ans=N-sum;
 if(ans<0){
  ans=-1;
 }
 std::cout<<ans<<std::endl;
}