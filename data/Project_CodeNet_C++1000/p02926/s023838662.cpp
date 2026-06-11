#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
struct point
{
	long double x, y;
}pos[105];
int Quadrant(point a)//象限排序，注意包含四个坐标轴
{
    if(a.x>0&&a.y>=0)  return 1;
    if(a.x<=0&&a.y>0)  return 2;
    if(a.x<0&&a.y<=0)  return 3;
    if(a.x>=0&&a.y<0)  return 4;
}
long double cross(long double x1, long double y1, long double x2, long double y2)  //计算叉积
{
	return (x1 * y2 - x2 * y1);
}
long double compare(point a, point b, point c)//计算极角
{
	return cross((b.x - a.x), (b.y - a.y), (c.x - a.x), (c.y - a.y));
}
bool cmp1(point a, point b)
{
  	point c;//原点
	c.x = 0;
	c.y = 0;
	if (compare(c, a, b) == 0)//计算叉积，函数在上面有介绍，如果叉积相等，按照X从小到大排序
		return a.x < b.x;
	else return compare(c, a, b) > 0;
}
bool cmp(point a,point b)  //先按象限从小到大排序 再按极角从小到大排序
{
    if(Quadrant(a)==Quadrant(b))//返回值就是象限
        return cmp1(a,b);
    else return Quadrant(a)<Quadrant(b);
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
	cout << fixed << setprecision(30) << sqrt(ans) << endl;
	return 0;
}