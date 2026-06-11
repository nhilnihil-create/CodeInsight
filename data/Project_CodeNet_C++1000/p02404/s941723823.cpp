#include <iostream>
using namespace std;

int main()
{
	int i, j, h, w;

	cin >> h >> w;

	while ((h!=0)&&(w!=0)) {
		for (i=0; i < w; i++)
			cout << '#';
		cout << endl;

		for (i=0; i < (h-2); i++) {
			cout << '#';
			for (j=0; j < (w-2); j++)
				cout << '.';
			cout << '#' << endl;
		}
		
		for (i=0; i < w; i++)
			cout << '#';
		cout << endl;

		cout << endl;
		cin >> h >> w;
	}
	return 0;
}