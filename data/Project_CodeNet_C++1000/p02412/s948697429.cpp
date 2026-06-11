#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;

	int i,j,k, count;
	while (n != 0 || x != 0) {
		i = 0;
		count = 0;

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n ; j++) {
				if(j!=i){
					for (k = 1; k <= n ; k++) {
						if (k != i && k != j) {
							if (i + j + k == x) {
//								cout << i << j << k << endl;
								count++;
							}
						}
					}
				}
			}
		}
		count /= 6;
		cout << count << endl;

		cin >> n >> x;
	}

	return 0;
}

