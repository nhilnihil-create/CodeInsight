#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
	int n, s[1000], sum;
	double d[1000], avg, sumsqdiv, stddiv;
	
	while(1){
		std::cin >> n;
		if(!n)
			break;
		sum = sumsqdiv = 0;
		for(int i=0; i<n; i++){
			std::cin >> s[i];
			sum += s[i];
		}
		avg = (double)sum / n;
		for(int i=0; i<n; i++){
			d[i] = s[i] - avg;
			sumsqdiv += d[i] * d[i];
		}
		stddiv = sqrt(sumsqdiv / n);
		std::cout << std::fixed << stddiv << std::endl;
	}
	return 0;
}