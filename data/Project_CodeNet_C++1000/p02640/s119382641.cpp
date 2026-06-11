#include<iostream>
using namespace std;
int main() {
	int x,y; cin >> x >> y;
	//a+b=x
	//4a+2b=y
	//2a=y-2x
	int a=(y-2*x)/2;
	if(y>=2*x && ((y-2*x)&1)==0 && a<=x) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}
