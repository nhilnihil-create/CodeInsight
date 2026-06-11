#include <iostream>
#include <string>

int main(){
 std::string T;
 std::cin>>T;
 for(int i=0;i<T.size();i++){
  if(T[i]=='?'){
   T[i]='D';
  }
 }
 std::cout<<T<<std::endl;
}