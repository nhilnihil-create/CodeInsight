#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int h, w, n, m;
int main(){
	cin >> h >> w >> n;
	m = std::max(h, w);
	cout << n / m + (bool)(n % m) << endl;
	return 0;
}