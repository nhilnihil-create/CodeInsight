#include <iostream>
#include <vector>
#include <map>

int main(){
 int N;
 std::cin>>N;
 std::vector<int> A(N);
 for(int i=0;i<N;i++){
  std::cin>>A[i];
 }
 
 std::map<int,int> sum;
 long long ans=0;
 for(int i=0;i<N;i++){
  ans+=sum[i-A[i]];
  sum[i+A[i]]++;
 }
 std::cout<<ans<<std::endl;
 
 return 0;
}