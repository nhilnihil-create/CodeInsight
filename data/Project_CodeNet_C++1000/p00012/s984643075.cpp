#include <iostream>
#include <cmath>

using namespace std;
typedef pair<double, double> P;

double helon(P p1, P p2, P p3)
{
	double a = sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
	double b = sqrt((p2.first - p3.first) * (p2.first - p3.first) + (p2.second - p3.second) * (p2.second - p3.second));
	double c = sqrt((p3.first - p1.first) * (p3.first - p1.first) + (p3.second - p1.second) * (p3.second - p1.second));
	double s = (a + b + c) / 2;
	return(sqrt(s * (s - a) * (s - b) * (s - c)));
}

void solve()
{
	P p[3];
	P xp;
	while(cin >> p[0].first >> p[0].second >> p[1].first >> p[1].second >> p[2].first >> p[2].second >> xp.first >> xp.second)
	{
		double square1 = helon(p[0], p[1], p[2]);
		double square2 = helon(p[0], p[1], xp);
		double square3 = helon(p[0], p[2], xp);
		double square4 = helon(p[1], p[2], xp);
		if(fabs(square1 - square2 - square3 - square4) < 1e-8)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}