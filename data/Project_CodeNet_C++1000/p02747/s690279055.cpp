#include<iostream>
#include<bits/stdc++.h>

int main(void){
  std::string s;
  std::cin>>s;
  
  for(int i=0;i<s.size();i+=2){
    if(s[i]=='h'){
      if(s[i+1]=='i'){
      }else{
        std::cout<<"No";
        exit(0);
      }
    }else{
      std::cout<<"No";
      exit(0);
    }
  }
  std::cout << "Yes";
  return 0;
}