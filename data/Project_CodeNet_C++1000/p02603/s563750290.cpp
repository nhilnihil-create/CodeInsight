#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

//MS D
int main(){
	int n;
	cin >> n;
	long long a[87];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long yen = 1000;
	for (int i = 1; i <= n - 1; i++){
		long long fx = 0;
		if (a[i] < a[i + 1]){
			fx = yen / a[i];
			yen += (a[i + 1] - a[i])*fx;
		}
	}
	cout << yen << endl;
	return 0;
}