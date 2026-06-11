#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
struct point
{
	double x, y;
}pos[105];
bool cmp(point a, point b)
{
	if (atan2(a.y, a.x) != atan2(b.y, b.x))
		return atan2(a.y, a.x) < atan2(b.y, b.x);
	else return a.x < b.x;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pos[i].x >> pos[i].y;
	sort(pos, pos + n, cmp);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		long long x = 0, y = 0;
		for (int j = 0; j < n; j++)	//注意可能构成环的情况
		{
			x += pos[(i + j) % n].x, y += pos[(i + j) % n].y;
			ans = max(ans, x * x + y * y);
		}
	}
	cout << fixed << setprecision(20) << sqrt(ans) << endl;
	return 0;
}