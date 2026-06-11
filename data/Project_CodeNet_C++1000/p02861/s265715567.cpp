#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	vector<double> x(n),y(n);

	for ( int i = 0; i < n; i++){
		cin >> x[i] >> y[i] ;
	}

	for ( int i = 0; i < n; i++){
		a[i] = i;
	}
	
	double sum = 0;
  	int count = 0;

	do{
		for( int i = 0; i < n-1; i++){
			sum += sqrt( (x[a[i]] - x[a[i+1]]) * (x[a[i]] - x[a[i+1]]) + (y[a[i]] - y[a[i+1]]) * (y[a[i]] - y[a[i+1]]));
		}
      	count++;
	}while(next_permutation(a.begin(),a.end()));

	cout << fixed << setprecision(10) << sum / count << endl;

	return 0;

}
