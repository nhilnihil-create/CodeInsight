#include <iostream>
using namespace std;

int main()
{
	int i=0,j, k, l, h[100], w[100];

	cin >> h[0] >> w[0];

	while ((h[i] != 0) && (w[i] != 0)) {
		i++;
		cin >> h[i] >> w[i];
	}

	for (j=0; j < i; j++) {

		for (k=0; k < w[j]; k++)
			cout << '#';
		cout << endl;

		for (k=0; k < (h[j]-2); k++) {
			cout << '#';
			for (l=0; l < (w[j]-2); l++)
				cout << '.';
			cout << '#' << endl;
		}
		
		for (k=0; k < w[j]; k++)
			cout << '#';
		cout << endl;
		
		cout << endl;
	}		
	return 0;
}