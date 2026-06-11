#include<iostream>

int main(){
	double D = 0;
	int T = 0;
	double S = 0;

	std::cin >> D >> T >> S;
	if (D/S <= T){
      std::cout << "Yes" << std::endl;
    }
  	else{
      std::cout << "No" << std::endl;
    }
	return 0;
}