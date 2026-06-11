#include <iostream>

int main(int argc, char **argv){
	for(int i = 1; i < 10; i++){
		for(int j = 1;j < 10; j++){
			std::cout << i << "x" << j << "=" << i * j;
			/* if(!(i == 9 && j == 9)){ */
				std::cout << std::endl;
			/* } */
		}
	}
}