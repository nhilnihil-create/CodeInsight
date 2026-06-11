#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
    
int main()
{
	float a, m;
	int n;
	cin >> n;
	while(n) {
		m = 0;
		int *s = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			m += s[i];
		}
		a = 0;
		for (int i = 0; i < n; i++)
			a += pow(s[i] - m / n , 2) / n;
		cout << fixed << setprecision(4) << sqrt(a) << endl;
		cin >> n;
	}
	return 0;
}