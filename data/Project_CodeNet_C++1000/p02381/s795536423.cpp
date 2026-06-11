#include "iostream"
#include "cmath"
#include "iomanip"
using namespace std;

int main(int argc, char const *argv[])
{
	int n=0;
	double m=0;
	double ans=0;
	while(true)
	{
		m=0;
		ans=0;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		int s[n];
		for(int i=0; i<n; i++)
		{
			cin >> s[i];
			m += s[i];
		}
		m /= n;

		for(int i=0; i<n; i++)
		{
			ans += pow(s[i]-m, 2);
		}
		ans /= n;
		ans = sqrt(ans);
		cout << fixed <<setprecision(10) << ans << endl;
	}

	return 0;
}
