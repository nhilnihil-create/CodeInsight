#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	while(1){
		int n;
		double ave = 0.0;
		double sum = 0.0;
		cin >> n;
		vector<int> data(n);
		if(n == 0) break;
		for(auto &a:data){
			cin >> a;
		}
		for(auto a:data){
			ave += a;
		}
		ave /= n;
		for(auto a:data){
			sum += (ave - a) * (ave - a);
		}
		printf("%.10lf\n",sqrt(sum/n));
	}
	return 0;
}	