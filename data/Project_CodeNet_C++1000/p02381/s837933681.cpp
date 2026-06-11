#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n; 

	cout << fixed << setprecision(4);

	while(cin >> n && n) {
		double s=0.0, s2=0.0, x;
		int n0 = n;

		while(n0-- && cin >> x) {
			s += x;
			s2 += x*x;
		}
		
		s /= n;
		s2 /= n;
		cout << sqrt(s2 - s*s) << '\n';
	}
	
	return 0;
}

