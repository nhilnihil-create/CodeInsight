#include <iostream>

using namespace std;
typedef long long ll;

int main(){
	ll X, K, D, min;
	cin >> X >> K >> D;
	X = abs(X);
	if ( K <= X / D)
		min = X - K * D;
	else if ((K - X / D ) % 2 == 0)
		min = X % D;
	else
		min = D - X % D;
	cout << min << endl;
	return 0;
}
