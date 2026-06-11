#include <iostream>
using namespace std;
int main(){
	int n, a,d=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 0)
			if (a % 3 != 0 && a % 5 != 0)
				d++;
	}
	if (d > 0)
		cout << "DENIED";
	else
		cout << "APPROVED";
}