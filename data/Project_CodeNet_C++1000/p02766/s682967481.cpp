#include <iostream>
using namespace std;
int main(){
	int n, k,a=0;
	cin >> n >> k;
	while (n > 0) {
		n /= k;
		a++;
	}
	cout << a;
}