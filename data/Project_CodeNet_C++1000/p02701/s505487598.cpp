#include <iostream>
#include <string>
#include <set>

int main(){
 int N;
 std::cin>>N;

 std::string tmp;
 std::set<std::string> s;
 for(int i=0;i<N;i++){
  std::cin>>tmp;
  s.insert(tmp);
 }

 int ans=0;
 for(auto p:s){
  ans++;
 }

 std::cout<<ans<<std::endl;

 return 0;
}