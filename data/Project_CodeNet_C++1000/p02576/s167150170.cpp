#include <iostream>
using namespace std;
int main() {
	int n;
	int x;
	int t;
	cin >> n>>x>>t;
	if (n%x == 0){
		cout << n/x*t  <<endl;
	}
	else {
		cout << (n/x+1)*t <<endl;
	}
}