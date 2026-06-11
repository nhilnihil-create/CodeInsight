#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define P_MAX 3
using namespace std;

int main(){
	int n, i, j, p;
	vector<int> x, y;
	double d, xy_sum, max=0, tmp;
	cin >> n;
	x.reserve(n);
	y.reserve(n);
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	for(i=0;i<n;i++){
		cin >> y[i];
	}
	for(p=1;p<=P_MAX;p++){
		xy_sum = 0;
		for(i=0;i<n;i++){
			tmp = 1;
			for(j=0;j<p;j++){
				tmp *= abs(x[i] - y[i]);
			}
			xy_sum += tmp;
		}
		d = pow(xy_sum, 1.0/(double)p);
		printf("%.6f\n", d);
	}
	//////////////p==???///////////////
	for(i=0;i<n;i++){
		tmp = abs(x[i]-y[i]);
		if(max < tmp) max = tmp;
	}
	printf("%.6f\n", max);
	return 0;
}