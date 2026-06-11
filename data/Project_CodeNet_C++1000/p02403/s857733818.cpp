#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>
using namespace std;

#ifndef M_PI
#define M_PI (4.0*atan(1.0))
#endif

int main() {
	// your code goes here
	int H,W;
	while(1){
		std::cin>>H>>W;
//		std::cout<<H<<" "<<W<<std::endl;
		if(H==0 && W==0) break;
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++) {
				std::cout<<"#";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}