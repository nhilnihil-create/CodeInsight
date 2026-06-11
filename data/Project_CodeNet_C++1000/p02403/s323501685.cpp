#include <iostream>
using namespace std;

int main()
{
	int i=0,n,ww,h[100], w[100];

	cin >> h[0] >> w[0];

	while ((h[i] != 0) && (w[i] != 0)) {
		i++;
		cin >> h[i] >> w[i];
	}

	n = i;
	i = 0;	

	while(i < n) {
		while(h[i]--) {
			ww = w[i];
			while(ww--)
				cout << '#';
			cout << endl;
		}
		cout << endl;
		i++;
	}	
	return 0;
}