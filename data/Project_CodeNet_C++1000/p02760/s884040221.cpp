#include <iostream>
using namespace std;
int main(){
	int a[1010], n, b;
	for (int i = 0; i < 9; i++)
		cin >> a[i];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b;
		for (int j = 0; j < 9; j++)
			if (a[j] == b)
				a[j] = 0;
	}
	if (a[0] + a[1] + a[2] == 0 || a[3] + a[4] + a[5] == 0 || a[6] + a[7] + a[8] == 0)
		cout << "Yes";
	else if (a[0] + a[3] + a[6] == 0 || a[1] + a[4] + a[7] == 0 || a[2] + a[5] + a[8]==0)
		cout << "Yes";
	else if (a[0] + a[4] + a[8] == 0 || a[2] + a[4] + a[6] == 0)
		cout << "Yes";
	else
		cout << "No";
}