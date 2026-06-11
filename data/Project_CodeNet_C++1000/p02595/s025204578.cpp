#include <iostream>
using namespace std;

int main(){
	long long int n, d, x, y,a=0;
	cin >> n>>d;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (x * x + y * y <= d*d)
			a++;
	}
	cout << a<<endl;
}