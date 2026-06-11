#include <iostream>
using namespace std;
int main()
{
	int K, A, B;
	int x = 0;
	cin >> K >> A >> B;
	if (A == B) {
		if (A % K == 0)
			cout << "OK" << "\n";
		else
			cout << "NG" << "\n";
	}
	else {
		int i = A;
		while (i <= B) {
			if (i % K == 0)
				x += 1;
			i++;
		}
		if (x == 0)
			cout << "NG" << "\n";
		else
			cout << "OK" << "\n";
	}
}