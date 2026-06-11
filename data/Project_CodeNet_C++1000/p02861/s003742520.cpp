#include <bits/stdc++.h>
using namespace std;
int main () {
	int N;
	cin >> N;
	int x[N], y[N];
	for (int i=0; i<N; i++) {
		cin >> x[i] >> y[i];
	}
	double sum=0.0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			sum+=sqrtl((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
	sum/=N;
	cout << fixed << setprecision(10)<< sum << endl;
}