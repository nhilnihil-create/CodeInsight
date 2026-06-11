#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

#define MAX 20000
using namespace std;



int main(){
  int a,b,c;
  std::cin >> a>>b>>c;
  if(a<b&&b<c){
    std::cout << "Yes" << '\n';
  }else{
    std::cout << "No" << '\n';
  }

}