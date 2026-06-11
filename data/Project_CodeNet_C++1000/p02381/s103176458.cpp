#include <iostream>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	int n;
	int a[1001];
	while(cin >> n && n)
	{
		double sum = 0;
		rep(i,n) 
		{
			cin >> a[i];
			sum += a[i];
		}

		sum /= n;
		double ans = 0;
		rep(i,n)
		{
			ans += ((a[i] - sum)*(a[i] - sum))/n;
		}
		cout << fixed;
		cout.precision(8);
		cout << sqrt(ans) << endl;
	}
	return 0;
}