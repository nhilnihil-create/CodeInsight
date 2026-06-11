#include<iostream>
using namespace std;
#include <vector>
#define re(i,n) for(int i = 0; i < n; i++)

int main() {
	int n;
	int p = 1;
	cin >> n;
	
	if (n < 10) cout << n << endl;
	else if (n < 100) cout << 9 << endl;
	else if (n < 1000) cout << 9 + (n - 99) << endl;
	else if (n < 10000) cout << 909 << endl;
	else if (n < 100000) cout << 909 + n - 9999 << endl;
	else cout << 90909 << endl;
	
	return 0;
}