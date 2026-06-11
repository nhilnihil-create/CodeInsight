#include <iostream>
using namespace std;
 
int main() {
 
	//code_goes_here-->
 
	long long  x;
	cin>>x;
 
	long long k =  1;
 
	while((k*x) % 360 != 0){
		k++;
	}
 
	cout<<k;
 
	return 0;
}