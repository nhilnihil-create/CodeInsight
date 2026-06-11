#include <iostream>
using namespace std;
long long int a[100006];
int main () {
	int N, zero=0;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> a[i];
		if (a[i]==0) {
			zero++;
		}
	}
	if (zero>0) {
		cout << "0" << endl;
		return 0;
	}
	long long int sum=1;
	for (int i=0; i<N; i++) {
		if (a[i]<=1000000000000000000/sum) {
			sum*=a[i];
		}
		else {
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << sum << endl;
}