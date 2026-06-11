#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{	
	while (1) {
		int n;
		cin >> n;		
		if (n == 0) break;
		
		int s[1000];
		for (int i = 0; i < n; i++) cin >> s[i];
		
		double m = 0;
		for (int i = 0; i < n; i++) {
			m += s[i];
		}
		m /= n;
		
		double aan = 0;
		for (int i = 0; i < n; i++) {
			aan += pow((s[i] - m), 2);
		}
		
		double a = sqrt(aan / n);
		
		cout << fixed << a << endl;
	}
		
	return 0;
}