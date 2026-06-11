#include <bits/stdc++.h>

int main(){  	
	std::string S;
	std::string T;
	std::cin >> S >> T;
  	int min = T.size();
  	int pass = S.size() - T.size();
  	for(int j=0;j <= pass;j++){
      int count = 0;
      for(int i = 0; i < T.size(); i++){
          if(T.at(i) != S.at(j + i)){
              count++;
          }
      }
      if(count < min){
      	min = count;
      }
    }
  	std::cout << min << std::endl;
	return 0;
}