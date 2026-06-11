#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define PI 3.141592

using namespace std;

class coodinate
{
public:
	double x;
	double y;
};


void koch_curve(int n, coodinate p, coodinate q)
{
	if (n == 0)
	{
		
		return;
	}

	coodinate left,mid,right;
	double length;

	length = sqrt(pow(q.x - p.x , 2) + pow(q.y - p.y , 2)) / 3;

	//printf("length=%f\n", length);

	left.x = (2 * p.x + q.x) / 3;
	left.y = (2 * p.y + q.y) / 3;

	right.x = (p.x + 2 * q.x) / 3;
	right.y = (p.y + 2 * q.y) / 3;

	mid.x = (right.x - left.x) * cos((60 * PI) / 180) - (right.y - left.y) * sin((60 * PI) / 180) + left.x;
	mid.y = (right.x - left.x) * sin((60 * PI) / 180) + (right.y - left.y) * cos((60 * PI) / 180) + left.y;

	koch_curve(n-1,p,left);
	printf("%f %f\n", left.x, left.y);

	koch_curve(n-1,left,mid);
	printf("%f %f\n", mid.x, mid.y);

	koch_curve(n-1,mid,right);
	printf("%f %f\n", right.x,right.y);

	koch_curve(n-1,right,q);

}

int main()
{
	int n;

	coodinate p1,p2;

	p1.x = 0;
	p1.y = 0;

	p2.x = 100;
	p2.y = 0;

	scanf("%d", &n);

	printf("%f %f\n", p1.x,p1.y);

	koch_curve(n,p1,p2);

	printf("%f %f\n", p2.x,p2.y);

	return 0;
}
	