#include <iostream>
#include <iomanip>
#include <cmath>
#define ll long long int
using namespace std;

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	cout << setprecision(15);
	int *a = new int[n];
	int *b = new int[n];
	for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			a[i] = x;
	}
	for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			b[i] = x;
	}
	int sum1 = 0;
	int sum2 = 0;
	ll sum3 = 0;
	int max = 0;
	for(int i = 0; i < n; i++){
			sum1 += abs(a[i] - b[i]);
			sum2 += (a[i] - b[i])*(a[i] - b[i]);
			sum3 += abs((a[i] - b[i])*(a[i] - b[i])*(a[i] - b[i]));
			if(max < abs(a[i] - b[i]))max = abs(a[i] - b[i]);
	}
	cout << sum1 << endl;
	cout << sqrt((double)sum2) << endl;
	cout << pow((double)sum3, 1./3) << endl;
	cout << max << endl;
	return 0;
}

