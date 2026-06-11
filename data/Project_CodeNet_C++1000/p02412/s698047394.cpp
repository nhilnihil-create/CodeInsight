#include <iostream>
using namespace std;
main () {
	int n, x;
	while (cin >> n >> x, n) {
		int a = 0;
		for (int i=1; i<=n-2; i++)
			for (int j=i+1; j<=n-1; j++)
				for (int k=j+1; k<=n; k++)
					if (i+j+k == x) a++;
		cout << a << endl;
	}
}