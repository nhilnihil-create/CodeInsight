#include <iostream>

using namespace std;

int main() 
{
	int K, X, i;
	cin >> K >> X;
	for (i = X - (K - 1); i <= X + (K - 1); i++) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}