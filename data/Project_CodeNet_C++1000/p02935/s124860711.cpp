#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	float t;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	sort(a,a+n);
	t=(a[0]+a[1])/2.0;
	for(int i=2;i<n;i++){
	    t=(t+a[i])/2.0;
	}
	cout<<t;
	return 0;
}