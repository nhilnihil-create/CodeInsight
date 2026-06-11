#include <cstdio>
using namespace std;

static const double PI = 3.14159265359;

int main()
{

	double r;

	scanf( "%lf", &r );
	printf( "%lf %lf\n", r * r * PI, r * 2 * PI );

	return 0;

}