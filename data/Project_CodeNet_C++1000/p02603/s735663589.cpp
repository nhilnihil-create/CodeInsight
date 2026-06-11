#include <iostream>
using namespace std;
int a[86];
int main () {
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> a[i];
	}
	long long int sum=1000, stk=0;
	for (int i=0; i<N; i++) {
		if (a[i]<a[i+1]) {
			stk+=sum/a[i];
			sum=sum-(sum/a[i]*a[i]);
		}
		else {
			sum+=stk*a[i];
			stk=0;
		}
	}
	cout << sum << endl;	
}