#include<cstdint>
#include<limits>
#include<cstdbool>
#include<cmath>
#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<sstream>
#include<algorithm>

int main(){
	int n;
	std::cin>>n;
	std::cin.get();
	std::vector<int> x;
	x.reserve(n);
	std::string buff;
	getline(std::cin,buff);
	std::stringstream ss(buff);
	int temp;
	while(!ss.eof()){
		ss>>temp;
		x.push_back(temp);
	}
	std::sort(x.begin(), x.end());
	std::cout<<x[n/2]-x[n/2-1];
	return 0;
}
