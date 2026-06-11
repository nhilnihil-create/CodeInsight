#include <iostream>
using namespace std;

int main() {
	int x,y;cin >> x>>y;
	if(y%2!=0){
		cout << "No" << endl;
		return 0;
	}
	int c = 2*x - y/2;
	int t = (y-2*x)/2;
	if(c>=0&&t>=0){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}