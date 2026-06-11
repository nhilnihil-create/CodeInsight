#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	while(cin >> n,n){
		double sum = 0.0;
		double m=0.0;
		vector<double> s(n);
		for(int i=0; i<n; i++){
			cin >> s[i];
			m += s[i]/n;
		}
		for(int i=0; i<n; i++)
			sum += pow(s[i]-m,2.0);
		cout << fixed << setprecision(8) << sqrt(sum/n) << endl;
	}
	return 0;
}