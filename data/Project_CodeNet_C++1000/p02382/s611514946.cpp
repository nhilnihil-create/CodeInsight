#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()

int aabs(double x){
	if(x<0) return x*=-1;
	else return x;

}
int main(){
	int n;
	int data1[150];
	int data2[150];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> data1[i];
	}
	for(int i=0;i<n;i++){
		cin >> data2[i];
	}
	double tmp = 0;
	for(int i=0;i<n;i++){
		tmp += aabs(data1[i]-data2[i]);
	}
	cout << fixed << setprecision(5) << tmp << endl;

	tmp = 0;
	for(int i=0;i<n;i++){
		tmp += ((data1[i]-data2[i])*(data1[i]-data2[i]));
	}
	cout << setprecision(5) << sqrt(tmp) << endl;

	tmp = 0;
	for(int i=0;i<n;i++){
		double t = aabs(data1[i]-data2[i]);
		tmp += t*t*t;
	}
	cout << setprecision(5) << cbrt(tmp) << endl;
	tmp = 0;
	for(int i=0;i<n;i++){
		if(tmp<aabs(data1[i]-data2[i])){
			tmp = aabs(data1[i]-data2[i]);
		}
	}
	cout << setprecision(5) << tmp << endl;
	return 0;

}