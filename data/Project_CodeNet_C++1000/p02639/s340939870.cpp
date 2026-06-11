#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a[5],sum=15;
	for(int i=0; i<5; i++){
		cin>>a[i];
	}
	for(int i=0;i<5;i++){
		sum=sum-a[i];
	}
	cout<<sum;
	return 0;
}