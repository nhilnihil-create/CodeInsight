#include <iostream>
using namespace std;

int main() {
	int n,in,min=1000000,max=-1000000;
	long sum=0;
	cin>>n;
	while(n--) {
		cin>>in;
		sum+=in;
		if(in>max) {
			max=in;
		}
		if(in<min) {
			min=in;
		}
	}
	cout<<min<<" "<<max<<" "<<sum<<endl;
	return 0;
}