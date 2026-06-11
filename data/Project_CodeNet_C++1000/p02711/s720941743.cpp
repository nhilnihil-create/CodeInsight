#include <iostream>
#include <string>

int main(){
 int N;
 std::cin>>N;

 int r=0;
 std::string ans="No";
 while(N!=0){
  r=N%10;
  N=N/10;
  if(r==7){
   ans="Yes";
   break;
  }
 }

 std::cout<<ans;
}