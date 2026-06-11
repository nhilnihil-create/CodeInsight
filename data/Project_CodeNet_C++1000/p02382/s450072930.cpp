#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double chebyshevDistance(vector<int> &x, vector<int> &y){
	double max = 0;
	vector<int>::iterator yi = y.begin();
	for(vector<int>::iterator xi = x.begin(); xi != x.end(); xi++){
		if(max < abs(*xi - *yi)){
			max = abs(*xi - *yi);
		}
		yi++;
	}
	return max;
}

double minkowskiDistance(vector<int> &x, vector<int> &y, double p){
	if(isinf(p)) return chebyshevDistance(x, y);

	double dPthPow = 0;
	vector<int>::iterator yi = y.begin();
	for(vector<int>::iterator xi = x.begin(); xi != x.end(); xi++){
		dPthPow += pow(abs(*xi - *yi), p);
		yi++;
	}
	return pow(dPthPow, 1 / p);
}

int main(){
	int n;
	cin >> n;
	vector<int> x, y;
	for(int i = 0; i < n; i++){
		int xi;
		cin >> xi;
		x.push_back(xi);
	}
	for(int i = 0; i < n; i++){
		int yi;
		cin >> yi;
		y.push_back(yi);
	}

	printf("%.6lf\n", minkowskiDistance(x, y, 1));
	printf("%.6lf\n", minkowskiDistance(x, y, 2));
	printf("%.6lf\n", minkowskiDistance(x, y, 3));
	printf("%.6lf\n", minkowskiDistance(x, y, 1.0/0.0));

	return 0;
}