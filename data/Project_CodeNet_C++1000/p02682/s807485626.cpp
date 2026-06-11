#include <iostream>
using namespace std;
int main(){
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	if (a + b <=k)cout << a - (k - a - b);
	else if (a <= k)cout << a;
	else cout << k;
}