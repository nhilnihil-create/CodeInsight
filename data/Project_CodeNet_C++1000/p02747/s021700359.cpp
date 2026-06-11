#include<iostream>
#include<string>
#include<regex>
 
int main(void){
  std::string input;
  std::regex re("(hi)+");
  
  std::cin >> input;
  
  if(regex_match(input,re)){
    std::cout << "Yes";
  }
  else{
  	std::cout << "No";
  }
  
  return 0;
}