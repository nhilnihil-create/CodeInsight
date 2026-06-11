#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin>>a>>b;
	if ((a>0 && a<21) || (a>0 && a<21)) 
		if (a>9 || b>9)
			cout<<-1;
		else
			cout<<a*b;
	
	return 0;
}