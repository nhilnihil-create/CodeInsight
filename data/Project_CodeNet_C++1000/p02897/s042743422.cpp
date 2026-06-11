#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n,ans;
	cin >> n;
	ans = (int(n + 1) / 2) / n;
	cout << fixed << setprecision(10) << ans;
}