#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
using namespace std;

double dis(int n,double p,int *x,int *y);

int main(){
	int n;
	cin >> n;
	int x[n],y[n],z = 0;
	
	for(int i = 0;i < n;i++)	cin >> x[i];
	for(int i = 0;i < n;i++)	cin >> y[i];
	
	for(int i = 0;i < n;i++){
		int a = abs(x[i] - y[i]);
		if(z < a)z = a;
	}
	
	
	cout << setprecision(18)
		 << dis(n,1,x,y) << "\n"
		 << dis(n,2,x,y) << "\n"
		 << dis(n,3,x,y) << "\n"
		 << z << "\n";
	return 0;
}

double dis(int n,double p,int *x,int *y){
	double ans = 0;
	for(int i = 0;i < n;i++){
		double ab;
		ab = abs(x[i] - y[i]);
		ans += pow(ab, p);
	}
	ans = pow(ans, 1/p);
	return ans;
}