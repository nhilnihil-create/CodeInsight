#include <iostream>
#include <vector>
#include <cmath>
double minkov(std::vector<int>&x ,std::vector<int>&y,int size ,int n)
{
	if(n == 0){
		double max = 0;
		for(int i = 0 ; i < size ; i ++){
			if(max <= std::abs(x[i]-y[i])){
				max = std::abs(x[i]-y[i]);
			}
		}
		return max;
	}else{
		double dist= 0;
		for(int i= 0 ; i < size ; i ++){
			dist += std::pow(std::abs(x[i] - y[i]),n);
		}
		return std::pow(dist,(double)1/n);
	}
}


int main(int argc, char const *argv[])
{
	int n,temp;
	std::vector<int> x ;
	std::vector<int> y ;
	std::cin >> n;
	for(int i = 0 ; i < n ; i ++){
		std::cin >> temp;
		x.push_back(temp);
	}
	for(int i = 0 ; i < n ; i ++){
		std::cin >> temp;
		y.push_back(temp);
	}
	printf("%lf\n%lf\n%lf\n%lf\n",minkov(x,y,n,1),minkov(x,y,n,2),minkov(x,y,n,3),minkov(x,y,n,0));
	return 0;
}