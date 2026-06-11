// 2014/08/01 Tazoe

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	while(true){
		int n;
		cin >> n;

		if(n==0)
			break;

		double s[1000];
		double sum = 0.0;
		for(int i=0; i<n; i++){
			cin >> s[i];

			sum += s[i];
		}

		double m = sum/(double)n;

		double sum2 = 0.0;
		for(int i=0; i<n; i++){
			sum2 += (s[i]-m)*(s[i]-m);
		}

		double a = sqrt(sum2/(double)n);

		cout.precision(8);
		cout << fixed << a << endl;
	}

	return 0;
}