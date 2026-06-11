#include <iostream>

int main(int ,char* ){

  for(int i = 1; i <= 9; ++i){
    for(int j = 1; j <= 9; ++j){
      std::cout << i << "x" << j << "=" << i*j << std::endl;
    }
  }

  return 0;
}