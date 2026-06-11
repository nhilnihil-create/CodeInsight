#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void){
	int n,p;
	int a[51];

	cin >> n; 
	cin >> p; 

	while (n != 0 || p != 0) {
		int fin = 0;
		int winner = 0;

		for (int i = 0; i < 51; i++) {
			if (i == 50) {
				a[i] = p;
			}else{
				a[i] = 0;
			}
		}
		while (!fin) {
			for (int i = 0; i < n && !fin; i++) {
				if (a[50] != 0) {
					a[i] += 1;
					a[50] -= 1;
				}else{
					a[50] += a[i];
					a[i] = 0;
					if (a[50] == p) {
						fin = 1;
						winner = i;
					}
				}
			}
		}
		cout << winner << endl;
		fin = 0;
		
		cin >> n;
		cin >> p;
	}

	return 0;
}