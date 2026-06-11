#include <iostream>
using std::cin;
using std::cout;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a < b && b < c) cout << "Yes\n";
	else cout <<"No\n";
	return 0;
}
