#include <iostream>

int main(int argc, char* argv[] ){
	int input;
	std::cin>> input;
	int hour = input / 3600;
	int min  = (input - hour*3600) /60;
	int sec  = input - hour*3600 - min*60;
	
	std::cout << hour << ":"<<min<<":"<<sec<<std::endl;
	
	}