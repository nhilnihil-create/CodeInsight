#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i=3; i <= n; i++) {
		if (i%3) {
			if (i%10==3)
				cout << ' ' << i;
			else if (i/10)
				if (i/10%10==3)
					cout << ' ' << i;
			else if (i/100)
				if (i/100%10==3)
					cout << ' ' << i;
			else if (i/1000)
				if (i/1000%10==3)
					cout << ' ' << i;
		}			
		else cout << ' ' << i;
	
	}
	cout << endl;
	return 0;
}