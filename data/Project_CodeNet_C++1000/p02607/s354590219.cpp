#include <iostream>
#include <string>
using namespace std;
int main() {

	int n,f, num=0;
	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> f;
		if ((i+1) % 2 != 0 && f % 2 != 0)
			num++;

	}
	cout << num;



}