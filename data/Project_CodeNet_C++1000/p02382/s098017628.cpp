#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> x, y;
	int n, tmp, p;
	double sum, ans;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		x.push_back(tmp);
	}
		for(int i = 0; i < n; i++){
		cin >> tmp;
		y.push_back(tmp);
	}

	for(p = 1; p <= 3; p++){
		sum = 0;
		for(int i = 0; i < n; i++)
			sum += pow((double)abs(x[i] -y[i]),(double)p);
		ans = pow(sum,(double)1/p);
		printf("%.8lf\n",ans);
	}
	ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, (double)abs(x[i]-y[i]));
	printf("%.8lf\n",ans);	return 0;
}