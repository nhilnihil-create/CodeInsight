#include <iostream>
#include <cmath>
#include <vector>

int main(int argc, char const *argv[])
{
	int n ;
	while(true){
		std::cin >> n;
		if(n == 0) break;
		std::vector<int> s;
		int temp;
		double ave = 0;
		double var = 0;
		for(int i = 0 ; i < n ; i++){
			std::cin >> temp;
			s.push_back(temp);
		}
		for(int e : s){
			ave += ((double)e/s.size());
		}
		for(int e : s){
			var += ((e-ave)*(e-ave)/s.size());
		}
		printf("%.7lf\n",std::sqrt(var));
	}
	return 0;
}