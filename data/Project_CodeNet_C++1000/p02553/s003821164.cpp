#include <iostream>
using namespace std;

int main() {
	long long a[2], b[2];
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	long long max=a[0]*b[0];
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			if(max<a[i]*b[j])max=a[i]*b[j];
		}
	}
	cout<<max;
	return 0;
}