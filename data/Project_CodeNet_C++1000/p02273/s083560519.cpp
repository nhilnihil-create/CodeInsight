#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

vector<vector<double>> ins(vector<vector<double>> a, int i)
{
	a.insert(a.begin() + i + 1, { (2 * a[i][0] + a[i + 1][0]) / 3, (2 * a[i][1] + a[i + 1][1]) / 3 });
	a.insert(a.begin() + i + 2, { (a[i][0] + 2 * a[i + 2][0]) / 3, (a[i][1] + 2 * a[i + 2][1]) / 3 });
	double u, v;
	u = (a[i + 2][0] + a[i + 1][0]) / 2 - (a[i + 2][1] - a[i + 1][1]) * sqrt(3) / 2;
	v = (a[i + 2][0] - a[i + 1][0]) * sqrt(3) / 2 + (a[i + 2][1] + a[i + 1][1]) / 2;
	a.insert(a.begin() + i + 2, { u, v });

	return a;
}

int main()
{
	vector<vector<double>> a = { { 0, 0 }, { 100, 0 } };
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < (int)pow(4, i); j++)
			a = ins(a, 4 * j);
	}

	for (unsigned int i = 0; i < a.size(); i++)
		cout << setprecision(8) << setiosflags(ios::fixed|ios::showpoint)
		<< a[i][0] << " " << a[i][1] << endl;

	return 0;
}