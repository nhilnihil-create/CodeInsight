#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

int main()
{
	faster;
	
	int a,b,h,m;
	cin >> a >> b >> h >> m;

	double ha =(30)*h,ma = 5.5*m;

	double angel = abs(ha-ma)* acos(-1) / 180;

	double res = a*a + b * b - (2.0* a * b * cos(angel));

	cout << fixed << setprecision(20) << sqrt(res) << endl;
	return 0;
}