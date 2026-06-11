#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	if(n%2==1)
	    cout<<(double(n+1))/(2*n);
	else
	    cout<<0.5;
	return 0;
}
