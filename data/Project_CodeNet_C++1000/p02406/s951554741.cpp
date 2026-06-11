#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

	int i, n, x;

	i = 2;

	cin >> n;

	while (1) {
		i++;
		x = i;
		if (x > n) break; 
		if (x % 3 == 0) {
			cout << " " << i;
			continue;
		}
		while(1) {
			if (x % 10 == 3) {
				cout << " " << i;
				break;
			}
			x /= 10;
			if (x == 0) break; 
		}
	}
	cout << endl;
	

	return (0);
}