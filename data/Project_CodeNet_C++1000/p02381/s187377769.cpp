#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

template <template<class T, class Allocator = allocator<T> > class Container>
double mean(Container<double> & x)
{
	return accumulate(x.begin(), x.end(), 0.0) / x.size();
}
template <template<class T, class Allocator = allocator<T> > class Container>
double var(Container<double> & x)
{
	double size = x.size();
	double x_mean = mean(x);
	return (inner_product(x.begin(), x.end(), x.begin(), 0.0) - x_mean * x_mean * size)/ size;
}
template <template<class T, class Allocator = allocator<T> > class Container>
double sd(Container<double> & x)
{
	return sqrt(var(x));
}
int main()
{
	while(1){
		int count;
		cin >> count;
		if (count == 0)break;
		std::vector<double> x;
		for(int i = 0; i < count; i++){
			int s;
			cin >> s;
			x.push_back(s);
		}
		cout << sd(x) << endl;
	}
	return 0;
}