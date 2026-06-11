#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	while(true) {

		int n;
		cin >> n;
		
		if(n == 0)	break;

		int a[n];
		double tmp1 = 0;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			tmp1 += a[i];
		}
		double avg = tmp1 / n;

		double tmp2 = 0;
		for(int i=0;i<n;i++) {
			tmp2 += (a[i]-avg)*(a[i]-avg);
		}
		double vari = tmp2 / n;

		printf("%.8f", sqrt(vari));
		cout << endl;
	}

    return 0;
}