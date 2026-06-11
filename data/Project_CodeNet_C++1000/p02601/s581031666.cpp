#include <iostream>

using namespace std;

int main(){
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	while (b <= a && k != 0){
		b *= 2;
		k -= 1;
	}
	while (c <= b && k != 0){
		c *= 2;
		k -= 1;
	}
	if (c > b && b > a) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
