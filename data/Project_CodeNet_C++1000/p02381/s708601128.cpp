#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		int n, i, j;
		double sum, a, SUM, m;
		double s[1001];
		while (1) {
				sum=0;
				SUM=0;
				cin >> n;
				if (n==0) break;
				for (i=0; i<n; i++) cin >> s[i];
				for (i=0; i<n; i++) sum += s[i];
				m = sum/n;
				for (i=0; i<n; i++) SUM += (s[i]-m)*(s[i]-m);
				cout << fixed << sqrt(SUM/n) << "\n";
		}
}