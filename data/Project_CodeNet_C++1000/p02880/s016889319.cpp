#include <iostream>
using namespace std;

int main() {
	int r;
	bool band=false;
	cin>>r;
	for (int a=1; a<10;a++) {
		for (int b=1; b<10;b++) {
			if (a*b==r)
				band=true;
		}
	}
	if (band)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}