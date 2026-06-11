#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n],o[n];
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	int s;
	for (int i=0; i<n; i++) {
		o[a[i]-1]=i+1;
	}
	for (int i=0; i<n; i++) {
		if (i==0) {
			cout<<o[i];
		} else {
			cout<<" "<<o[i];
		}
	}
	cout<<endl;
	return 0;
}