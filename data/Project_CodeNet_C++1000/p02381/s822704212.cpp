#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	int n, sum;
	double ave, tmp, stdev;
	while (cin >> n, n != 0){
		vector <int> s(n);
		for (int i=0; i<n; i++)
			cin >> s[i];

		sum = 0;
		for (int i=0; i<n; i++)
			sum += s[i];
		ave = (double)sum / n;

		tmp =0;
		for (int i=0; i<n; i++)
			tmp += pow((s[i]-ave),2);
		stdev = sqrt(tmp/n);

		cout << fixed << stdev << endl;
	}
	return 0;
}