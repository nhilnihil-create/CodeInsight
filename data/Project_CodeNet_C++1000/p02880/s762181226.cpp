#include<iostream>
int main(void){
  int N;
  std::cin >> N;
  bool b = false;
  for (int i=1;i<10;i++){
    for (int j=i;j<10;j++){
      if (N == i*j) b = true;
    }
  }
  if(b){
    std::cout << "Yes" << std::endl;
  }else{
    std::cout << "No" << std::endl;
  }
  return 0;
}