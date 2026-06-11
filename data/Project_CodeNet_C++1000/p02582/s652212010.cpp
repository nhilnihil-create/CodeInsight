#include <iostream>

int main(){
	std::string str;
  std::cin >> str;
  bool lstR = false;
  int ret = 0;
  int cur = 0;
  for (auto it : str) {
  	if (it == 'R') {
    	cur ++;
      lstR = true;
    }else if (it == 'S'){
    	if (lstR) {
        	cur = 0;
        }
      lstR = false;
    }
    ret = ret > cur ? ret : cur;
  }
  std::cout << ret << std::endl;
}