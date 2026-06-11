#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+10);
	long long s = 0;
	for (int i = 1; i <= n; i++){
	       	cin >> a[i];
		s += a[i];
	}

	vector<long long> x(n+10);
	x[1] = s;
	for (int i = 2; i <= n-1; i += 2) x[1] -= 2*a[i];
	cout << x[1] << ' ';
	for (int i= 2; i <= n; i++){
		x[i] = 2*a[i-1] - x[i-1];
		cout << x[i] << ' ';
	}
	cout << endl;
	return 0;
}