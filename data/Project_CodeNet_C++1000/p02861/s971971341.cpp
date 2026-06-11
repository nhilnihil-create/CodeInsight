#include <bits/stdc++.h>
using namespace std;

double distance(double arr[][2], int i, int num[]){
	int ind = num[i];
	int ind1 = num[i+1];
	double x1 = arr[ind][0];
	double y1 = arr[ind][1];
	double x2 = arr[ind1][0];
	double y2 = arr[ind1][1];
	double d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	d = pow(d, 0.5);
	return d;
}

int main(){
	int n;
	cin>>n;
	double arr[n][2];
	int num[n];
	for (int i = 0; i<n; i++){
		cin>>arr[i][0]>>arr[i][1];
		num[i] = i;
	}
	double ans = 0;
	double div = 1;
	for (int i = n; i>=1; i--){
		div*=i;
	}
	do{
		for (int i = 0; i<n-1; i++){
			ans+=distance(arr,i,num);
		}
	}while(next_permutation(num,num+n));
	cout<<fixed<<setprecision(12)<<ans/div;
	return 0;
}