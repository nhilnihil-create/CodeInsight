#include <iostream>
#include <iomanip>


int main(int argc, char **argv){
	int a = 0;
	int b = 0;

	std::cin >> a >> b;

	std::cout << a / b << " " << a % b << " " 
		<< std::fixed << std::setprecision(6) <<
		(double)a / b << std::endl;
	
	return 0;
}