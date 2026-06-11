#include <iostream>
#include<string>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	
	int n, ans;

	cin >> n;

	cout << ((n%2==0) ? (n/2)-1:floor(n/2)) << endl;
	return 0;
}