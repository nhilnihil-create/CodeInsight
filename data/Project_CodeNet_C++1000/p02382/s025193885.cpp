#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<double> x(n),y(n);
	for(auto &a:x){
		cin >> a;
	}
	for(auto &a:y){
		cin >> a;
	}
	//p = 1
	double sum = 0.0;
	for(int i = 0; i < n; i++){
		sum += fabs(x[i] - y[i]);
	}
	printf("%.10lf\n",sum);
	//p = 2
	sum = 0.0;
	for(int i = 0; i < n; i++){
		sum += pow(fabs(x[i] - y[i]),2);
	}
	printf("%.10lf\n",sqrt(sum));
	//p = 3
	sum = 0.0;
	for(int i = 0; i < n; i++){
		sum += pow(fabs(x[i] - y[i]),3);
	}
	printf("%.10lf\n",pow(sum,1.0/3.0));
	//p = ??????
	sum = fabs(x[0] - y[0]);
	for(int i = 1; i < n; i++){
		if(sum < fabs(x[i] - y[i])) sum = fabs(x[i] - y[i]);
	}
	printf("%.10lf\n",sum);
	return 0;
}