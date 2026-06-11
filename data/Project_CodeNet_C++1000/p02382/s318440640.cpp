#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, x;
	vector<int> a, b;
	vector<double> c;
	double dis1 = 0, dis2 = 0, dis3 = 0;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++){
		cin>>x;
		b.push_back(x);
		c.push_back(abs(a[i]-b[i]));
	}

	for(int i=0;i<n;i++){
		dis1 += c[i];
		dis2 += pow(c[i], 2);
		dis3 += pow(c[i], 3);
	}
	sort(c.begin(), c.end());

	printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n", dis1, sqrt(dis2), pow(dis3, 1/(double)3), c[n-1]);
	return 0;
}