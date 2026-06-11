#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string str; 
    
  std::cin >> n;
  std::cin >> str;
  
  if (n % 2 == 1 ){
    std::cout << "No";
  } else if (str.substr(0,n/2) == str.substr(n/2,n/2)){
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}
