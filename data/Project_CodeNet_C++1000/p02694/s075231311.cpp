#include <iostream>
using namespace std;
int main(){
	long long x,a = 100, i = 0; 
	cin >> x;
	while (a < x) {
		a += a / 100;
		i++;
	}
	cout << i;
}