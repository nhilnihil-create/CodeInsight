#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> x(n, 0), y(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> x[i];

	for (int i = 0; i < n; ++i)
		cin >> y[i];

	// ???????????????????????¢(p = 1)
	double md = 0.0;
	double p = 1.0;
	for (int i = 0; i < n; ++i)
		md += pow(abs(x[i] - y[i]), p);
	md = pow(md, 1 / p);

	// ???????????????????????¢(p = 2)
	double ed = 0.0;
	p = 2.0;
	for (int i = 0; i < n; ++i)
		ed += pow(abs(x[i] - y[i]), p);
	ed = pow(ed, 1 / p);

	// p = 3?????¨???
	double td = 0.0;
	p = 3.0;
	for (int i = 0; i < n; ++i)
		td += pow(abs(x[i] - y[i]), p);
	td = pow(td, 1 / p);

	// ?????§????????§????????¢(p = ???)
	double cd = 0.0;
	for (int i = 0; i < n; ++i)
		if (abs(x[i] - y[i]) > cd)
			cd = abs(x[i] - y[i]);

	cout << setprecision(16) << md << endl;
	cout << ed << endl;
	cout << td << endl;
	cout << cd << endl;

	return 0;
}