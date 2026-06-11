#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
struct Point
{
	LL x, y;
	Point(LL x = 0, LL y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

LL cross(const Point& p1, const Point& p2)
{
	return (p1.x * p2.y - p1.y * p2.x);
}
bool cmp1(const Point& a, const Point& b)
{
	return cross(a, b) > 0;
}

int Quadrant(const Point& a)
{
	if (a.x > 0 && a.y >= 0)  return 1;
	if (a.x <= 0 && a.y > 0)  return 2;
	if (a.x < 0 && a.y <= 0)  return 3;
	if (a.x >= 0 && a.y < 0)  return 4;
	return 0;
}
bool cmp(const Point& a, const Point& b)  //先按象限从小到大排序 再按极角从小到大排序
{
	if (Quadrant(a) == Quadrant(b))//返回值就是象限
		return cmp1(a, b);
	else return Quadrant(a) < Quadrant(b);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<Point> vp;
	for (int i = 0; i < n; i++)
	{
		LL x, y;
		cin >> x >> y;
		vp.emplace_back(x, y);
	}
	sort(vp.begin(), vp.end(), cmp);
	for (int i = 0; i < n; i++) vp.push_back(vp[i]);
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		LL sumx = 0, sumy = 0;
		for (int j = i; j < i + n; j++)
		{
			sumx += vp[j].x;
			sumy += vp[j].y;
			ans = max(ans, sumx * sumx + sumy * sumy);
		}
	}
	printf("%.15f\n", sqrt(ans));
	return 0;
}