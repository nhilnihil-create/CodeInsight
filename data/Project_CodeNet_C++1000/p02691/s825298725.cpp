#include<iostream>
#include<map>
int main(){
  int n;
  std::cin>>n;
  int64_t ans = 0;
  std::map<int,int64_t> mp;
  for(int i=1;i<=n;++i){
    int ai;
    std::cin>>ai;
    ans += mp[i-ai];
    mp[ai+i]++;
  }
  std::cout<< ans <<std::endl;
}