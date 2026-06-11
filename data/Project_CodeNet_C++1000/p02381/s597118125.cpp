#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	while(n!=0){
		int s[n];
		int sum=0;
		for(int i = 0; i < n; i++){
			cin >>s[i];
			sum += s[i];
		}
		double m = (double)sum/n;
		double a =0;
		for(int i = 0; i < n; i++){
			a+=(s[i]-m)*(s[i]-m);
		}
		cout<<setprecision(10)<<sqrt(a/n)<<endl;
		cin >> n;
	}
	
}
