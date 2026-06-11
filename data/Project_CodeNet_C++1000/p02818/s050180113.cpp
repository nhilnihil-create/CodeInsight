#include <iostream>
using namespace std;
int main(){
	long long int a, b, k;
	cin >> a >> b >> k;
	if (a > k)
		cout << a - k << " " << b;
	else if (a + b < k)
		cout << 0 << " " << 0;
	else
		cout << 0 << " " << b - k + a;
}