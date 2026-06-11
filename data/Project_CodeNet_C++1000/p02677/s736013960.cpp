#include <iostream>
#include <math.h>

using namespace std;

double degree(int hours, int minutes)
{
	double degrees, A , B;
	
	A = (double)hours*5 + (double)minutes/12;
	B = minutes;
	degrees = abs(A - B) * 6;

	if (degrees > 180)
	{
		degrees = 360 - abs(A - B)*6;
	}

	return degrees;
}

int main()
{
	const double PI = 3.14159265358979323846;

	int A, B, H, M;

	cin >> A >> B >> H >> M;

	double uhel;
	uhel = degree(H, M) / 180 * PI;

	double lenght;
	lenght = sqrt(pow(A, 2) + pow(B, 2) - 2 * (double)A * (double)B * cos(uhel));

	printf("%.11f", lenght);

	return 0;
}